%{
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

extern int yylineno;
extern int column;
extern int yylex(void);

typedef struct symbolT{
	char* name;	
	char *type;								
	char *strV;	
	int intV;						
	int init;							
	int isconst;	
	float floatval;							
	struct symbolT *next;
} symbol;

symbol* insertToTable (char* name, char* type, int isconst);
symbol* findInSymbolT(char* name);

char* StrCat(char* char1, char* char2);
char* getLabel();
char* getTreg();
char* getFreg();
char* regOfS;
char* mipsCod;

void freeTreg(char* reg);
void freeFreg(char* reg);
void outputError(char* s);
void yyerror(char* s);

int isError = 1;
%}

%locations

%union{
struct number{
char* type;
 union {
	 int ival;							  
	 float fval;							 
} val;
} number;

struct declar{
int ival;
float fval;
char *idvalue;
char *type;
char *arrrray[5];
char *reg;
char *label;
char *codeHead;
char *codeBody;
} dec;

struct mipsCod{
char *label;
char *head;
char *body;
} code;

enum{PLUS,MINUS,MUL,DIV,ASSIGN,OR,AND,EQ,NEQ,LT,GT,GTEQ,LTEQ} op;
char* sval;
}

%token <sval> ID SENTENCE
%token <op> ADDOP MULOP ASSIGNOP OROP ANDOP RELOP
%token <number> NUM 
%token BREAK CASE DEFAULT DO ELSE END INT PROGRAM REAL READ BGN STRING SWITCH TILL VAR IF WHILE LET FINAL OUT WITH FOREACH
%type <dec> EXPRESSION TERM FACTOR DECLARATIONS DECLARLIST LIST DECL CDECL TYPE switch CHOICE CASES BOOLEXPR BOOLTERM BOOLFACTOR  
%type <code> STMTLIST STMT ASSIGNMENT_STMT OUT_STMT READ_STMT CONTROL_STMT STMT_BLOCK STEP
%start MAIN
%% 

MAIN: PROGRAM ID BGN DECLARATIONS STMTLIST END 

{
 printf("MAIN -> PROGRAM ID BGN DECLARATIONS STMTLIST END \n");
 char* str = (char*)malloc(sizeof(char*) * 1000);
 str[0]='\0';
 if($5.head == NULL){ 
   $5.head="";
 }
  
 if($4.codeBody == NULL) { 
	$4.codeBody="";
 }
    
 sprintf(str,".data\n%s\n%s\nstrBuff: .space 200\n.text\nmain:\n%s\n%s\n", $4.codeHead, $5.head, $4.codeBody, $5.body);
 mipsCod = str;
}
;

DECLARATIONS:  LET  DECLARLIST CDECL 

{
 printf("DECLARATIONS -> LET  DECLARLIST CDECL\n");
 $$.codeHead = strdup(strcat($2.codeHead, $3.codeHead));
 $$.codeBody = strdup($3.codeBody);
}

| 

{
 printf("DECLARATIONS -> empty \n");
 $$.codeHead = strdup("");
 $$.codeBody = strdup("");
}
;

DECLARLIST: DECLARLIST DECL

{
 printf("DECLARLIST -> DECLARLIST DECL \n");
 $$.codeHead = StrCat($1.codeHead, $2.codeHead);
}

| DECL 

{
 printf("DECLARLIST -> DECL \n");
 $$.codeHead = strdup($1.codeHead);
}
; 

DECL:  TYPE ':' LIST

{
 printf("DECL -> TYPE ':' LIST \n");
 
 char* codeHeadStr = (char*)malloc(sizeof(char) * 100);
 char* codeHeadStrTmp = (char*)malloc(sizeof(char) * 100);
 codeHeadStr[0]='\0';
 codeHeadStrTmp[0]='\0';
 
 char* str;
 int i;
 for(i = 0 ; i < 5 ; i++)
 {
  if($3.arrrray[i] != NULL)
  {
   if(findInSymbolT($3.arrrray[i]) == NULL)
   {
    insertToTable($3.arrrray[i], $1.type, 0);
    if(strcmp($1.type, "string") == 0)
    {
     sprintf(codeHeadStrTmp, "%s: .space 200\n", $3.arrrray[i]);
     strcat(codeHeadStr, codeHeadStrTmp);
    }
    else
    {
     sprintf(codeHeadStrTmp, "%s: .space 8\n", $3.arrrray[i]);
     strcat(codeHeadStr, codeHeadStrTmp);
    }
   }
   else 
   {
    outputError("Double declaration. Already declared.");
    sprintf(codeHeadStr, "");
    isError = 0;
   }
  }
 }
 
 $$.codeHead = strdup(codeHeadStr);
 free(codeHeadStr);
 free(codeHeadStrTmp);
}
;

LIST: ID ',' LIST

{
 printf("LIST -> ID ',' LIST \n");
 
 int i, j;
 for(i = 0 ; i < 5 ; i++)
 {
  if($$.arrrray[i] == NULL)
  {
   $$.arrrray[i] = $1;
   for(j = 0 ; j < 5 ; j++)
   {
     if($3.arrrray[i] != NULL)
     {
      $$.arrrray[i+1] = $3.arrrray[j];
      i++;
     }
   }
   break;
  }
 }
}

|ID ';'

{
 printf("LIST -> ID ';' \n");
 
 int i;
 for(i = 0 ; i < 5 ; i++)
 {
  if($$.arrrray[i] == NULL)
  {
   $$.arrrray[i] = $1;
   break;
  }
 }
}
;

TYPE:  INT

{
 printf("TYPE -> INT \n");
 $$.type = strdup("int");
}

| REAL

{
 printf("TYPE -> REAL \n");
 $$.type = strdup("float");
}

| STRING

{
 printf("TYPE -> STRING \n");
 $$.type = strdup("string");
}
; 

CDECL: FINAL TYPE ID ASSIGNOP NUM ';' CDECL 

{
 printf("CDECL -> FINAL TYPE ID ASSIGNOP NUM ';' CDECL \n");
 
 symbol* sym = NULL;  
 char* codeHeadStr = (char*)malloc(sizeof(char) * 100);
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 codeHeadStr[0] = '\0';
 codeBodyStr[0] = '\0';
 
 if(findInSymbolT($3) == NULL)
 {
  sym = insertToTable($3, $2.type, 1);
  if(strcmp($2.type, "string") == 0)
  {
	  sprintf(codeHeadStr,"%s: .space 200\n", $3);
  }
  else
  {
   sprintf(codeHeadStr, "%s: .space 8\n", $3);
   if(strcmp($2.type, "int") == 0)
   {
	   sprintf(codeBodyStr, "li $t0,%d\nsw $t0, %s\n", $5.val, $3);  
   }
  }
 }
 else
 {
  outputError("Double declaration. Already declared.");
  sprintf(codeHeadStr,"");
  isError = 0;
 }
 
 $$.codeHead = StrCat(codeHeadStr, $7.codeHead);
 $$.codeBody = StrCat(codeBodyStr, $7.codeBody);
}

|
 
{
 printf("CDECL -> empty \n");
 $$.codeHead = strdup("");
 $$.codeBody = strdup("");
}
;

STMTLIST: STMTLIST STMT

{
 printf("STMTLIST -> STMTLIST STMT \n");
 $$.body = StrCat($1.body, $2.body);
}

| 

{
 printf("STMTLIST -> EMPTY \n");
 $$.head = strdup("");
 $$.body = strdup("");

}
;

STMT: ASSIGNMENT_STMT

{
 printf("STMT -> ASSIGNMENT_STMT \n");
 $$.head = strdup($1.head);
 $$.body = strdup($1.body);
}

| ID ASSIGNOP SENTENCE ';'

{
 printf("STMT -> ID ASSIGNOP SENTENCE ';' \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* codeHeadStr = (char*)malloc(sizeof(char) * 100);
 char* reg = getTreg();
 codeBodyStr[0]='\0';
 codeHeadStr[0]='\0';
 
 char* label = getLabel();
 symbol* sym = findInSymbolT($1);
 
 if (sym != NULL)
 {
  if(sym->isconst == 0)
  {
   if(strcmp(sym->type,"string") == 0)
   {
    sym->strV = strdup($3);
    sprintf(codeHeadStr,"%s: .asciiz %s\n", label, $3);
    sprintf(codeBodyStr, "lw %s, %s\nsw %s, %s\n", reg, label, reg, $1);
   }
   else
   {
    outputError("trying to assign sentence to an id that is not type sentence");
    sprintf(codeBodyStr, "");
    isError = 0;
   }
  }
  else
  {
   outputError("Can't assign to constant!");
   sprintf(codeBodyStr, "");
   isError = 0;
  }
 }
 else
 {
  outputError("id is not declared!. Please declare id.");
  sprintf(codeBodyStr, "");
  isError = 0;
 }
 
 freeTreg(reg);
 
 $$.head = strdup(codeHeadStr);
 $$.body = strdup(codeBodyStr);
 
 free(codeHeadStr);
 free(codeBodyStr);
}

| CONTROL_STMT

{
 printf("STMT -> CONTROL_STMT \n");
 $$.head = strdup($1.head);
 $$.body = strdup($1.body);
}

| READ_STMT

{
 printf("STMT -> READ_STMT \n");
 $$.body = strdup($1.body);
}

| OUT_STMT

{
 printf("STMT -> OUT_STMT \n");
 $$.head = strdup($1.head);
 $$.body = strdup($1.body);
}

| STMT_BLOCK 

{
 printf("STMT -> STMT_BLOCK \n");
 $$.head = strdup($1.head);
 $$.body = strdup($1.body);
}
;

OUT_STMT: OUT '(' EXPRESSION ')' ';' 

{
 printf("OUT_STMT -> OUT '(' EXPRESSION ')' ';' \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 codeBodyStr[0]='\0';
 
 if(strcmp($3.type, "int") == 0)
 {
	 sprintf(codeBodyStr, "li $v0,1\nmove $a0,%s\n syscall\n", $3.reg);
 }
  
 if(strcmp($3.type,"float") == 0)
 {
	sprintf(codeBodyStr, "li $v0,2\nmov.s $f12,%s\n syscall\n", $3.reg); 
 }
  
 $$.head = $3.codeHead;
 $$.body = StrCat($3.codeBody,codeBodyStr);
 free(codeBodyStr);
}

| OUT '(' SENTENCE ')' ';' 

{
 printf("OUT_STMT -> OUT '(' SENTENCE ')' ';' \n"); 
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* codeHeadStr = (char*)malloc(sizeof(char) * 100);
 char* label = getLabel();
 codeBodyStr[0]='\0';
 codeHeadStr[0]='\0';
 
 sprintf(codeHeadStr,"%s: .asciiz %s\n", label, $3);
 sprintf(codeBodyStr, "la $a0,%s\nli $v0,4\nsyscall\n", label);
 
 $$.head = strdup(codeHeadStr);
 $$.body = strdup(codeBodyStr);
 free(codeHeadStr);
 free(codeBodyStr);
}

| OUT {outputError("expected '('"); isError = 0;} error SENTENCE ')' ';'

{
 $$.body = strdup("");
 $$.head=strdup("");
}

| OUT '(' SENTENCE {outputError("expected ')'");isError = 0;} error ';'

{
 $$.body = strdup("");
 $$.head=strdup("");
}

| OUT '(' SENTENCE ')' {outputError("expected ';'");isError = 0;} error

{
 $$.body = strdup("");
 $$.head=strdup("");
}
;

READ_STMT: READ '(' ID ')' ';' 

{
 printf("READ_STMT -> READ '(' ID ')' ';' \n");
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);	
 codeBodyStr[0]='\0';
 
 symbol* sym = findInSymbolT($3);
 
 if (sym != NULL)
 {
  if(sym->isconst == 0)
  {
   if(strcmp(sym->type, "int") == 0)
   {
	   sprintf(codeBodyStr, "li $v0,5\nsyscall\nsw $v0, %s\n", sym->name);
   }
    
   if(strcmp(sym->type,"float") == 0)
   {
	   sprintf(codeBodyStr, "li $v0,6\nsyscall\ns.s $f0, %s\n", sym->name);
   }
    
   if(strcmp(sym->type,"string") == 0)
   {
    strcat(codeBodyStr, "li $v0,8\nla $a0,");
    strcat(codeBodyStr, sym->name);
    strcat(codeBodyStr, "\nli $a1,200\nsyscall\n");
   }
  }
  else
  {
   outputError("Can't assign to constant!");
   sprintf(codeBodyStr, "");
   isError = 0;
  }
 }
 else
 {
  outputError("id is not declared!. Please declare id.");
  sprintf(codeBodyStr, "");
  isError = 0;
 }
 $$.body = strdup(codeBodyStr);
}
;

ASSIGNMENT_STMT: ID ASSIGNOP EXPRESSION ';'

{
 printf("ASSIGNMENT_STMT -> ID ASSIGNOP EXPRESSION ';' \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 codeBodyStr[0]='\0';
 
 char* reg;
 symbol* sym = findInSymbolT($1);
 
 if (sym != NULL)
 {
  if(sym->isconst == 0)
  { 
   if(strcmp($3.type, "int") == 0 && strcmp($3.type, sym->type) == 0)
   {
    sprintf(codeBodyStr, "sw %s, %s\n", $3.reg, $1);
    freeTreg($3.reg);
   }	
   else if(strcmp($3.type, "float") == 0 && strcmp($3.type, sym->type) == 0)
   {
    sprintf(codeBodyStr, "s.s %s, %s\n", $3.reg, $1);
    freeFreg($3.reg);
   }
   else
   {
    if(strcmp($3.type, "int") == 0 && strcmp("float", sym->type) == 0)
    {
     reg = getFreg();
     sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\ns.s %s, %s\n", $3.reg, reg, reg, reg, reg, $1);
     freeTreg($3.reg);
     freeFreg(reg);
    }
    else
    {
     outputError("Can't convert from real to integer");
     sprintf(codeBodyStr, "");
     isError = 0;
    }
   }
  }
  else
  {
   outputError("Can't assign to constant!");
   sprintf(codeBodyStr, "");
   isError = 0;
  }
 }
 else
 {
  outputError("ID is not declared!. Please declare id.");
  sprintf(codeBodyStr, "");
  isError = 0;
 }
 
 $$.head = strdup($3.codeHead);
 $$.body = StrCat($3.codeBody,codeBodyStr);
 free(codeBodyStr);
}
;

CONTROL_STMT: IF '('BOOLEXPR')' STMT ELSE STMT

{
 printf("CONTROL_STMT -> IF '('BOOLEXPR')' STMT ELSE STMT \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * (100 + strlen($5.body)));
 char* label = getLabel();
 char* str;
 codeBodyStr[0]='\0';
 
 sprintf(codeBodyStr, "beq %s, $0,Else%s\n%s\nj\n%s\nEnd%s:\n", $3.reg, label, label, $5.body, label);	
 str = StrCat(str,$5.head);
 
 $$.head = StrCat($3.codeHead,str);
 $$.body = StrCat($3.codeBody,codeBodyStr);
 freeTreg($3.reg);
 free(str);
 free(codeBodyStr);
}

| IF {outputError("expected '('");isError = 0;} error BOOLEXPR ')' STMT ELSE STMT 

{
 $$.body=strdup("");
 $$.head=strdup("");
}

|  IF '('  error {outputError("Expected to recieve a boolean expression");isError = 0;} ')' STMT ELSE STMT

{
 $$.body=strdup("");
 $$.head=strdup("");
}

|  IF '(' BOOLEXPR {outputError("expected ')'");isError = 0;} error STMT ELSE STMT

{
 $$.body=strdup("");
 $$.head=strdup("");
}

| WHILE '(' BOOLEXPR ')' STMT_BLOCK

{
 printf("CONTROL_STMT -> WHILE '(' BOOLEXPR ')' STMT_BLOCK \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * (100 + strlen($5.body)));
 char* label = getLabel();
 char* str = (char*)malloc(sizeof(char) * (50 + strlen($3.codeBody)));
 codeBodyStr[0]='\0';
 str[0]='\0';
 
 sprintf(codeBodyStr, "beq %s, $0, End%s\n%s\nj Loop%s\nEnd%s:\n", $3.reg, label, $5.body, label, label);
 sprintf(str,"Loop%s:\n",label);
 strcat(str, $3.codeBody);
 
 $$.head = StrCat($3.codeHead, $5.head);
 $$.body = StrCat(str,codeBodyStr);
 freeTreg($3.reg);
 free(str);
 free(codeBodyStr);
}

| WHILE {outputError("expected '('");isError = 0;} error BOOLEXPR ')' STMT_BLOCK 

{
 $$.body=strdup("");
 $$.head=strdup("");	
}

| WHILE '(' error {outputError("Expected to recieve a boolean expression");isError = 0;} ')' STMT_BLOCK 

{
 $$.body=strdup("");
 $$.head=strdup("");
} 

| WHILE '(' BOOLEXPR {outputError("expected ')'");isError = 0;} error STMT_BLOCK 

{
 $$.body=strdup("");
 $$.head=strdup("");
}

| FOREACH ID ';' ASSIGNOP ';' NUM  ':' NUM  WITH STEP STMT
{
 printf("CONTROL_STMT -> FOREACH ID ';' ASSIGNOP ';' NUM  ':' NUM  WITH STEP STMT \n");

}
| FOREACH ID ';' ASSIGNOP ';' NUM  ':' ID  WITH STEP STMT
{
 printf("CONTROL_STMT -> FOREACH ID ';' ASSIGNOP ';' NUM  ':' ID  WITH STEP STMT \n");

}

| DO STMT_BLOCK TILL '(' BOOLEXPR ')'

{
 printf("CONTROL_STMT -> DO STMT_BLOCK TILL '(' BOOLEXPR ')' \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * (100 + strlen($2.body)));
 char* label = getLabel();
 char* str = (char*)malloc(sizeof(char) * (50 + strlen($5.codeBody)));
 codeBodyStr[0]='\0';
 str[0]='\0';
 
 sprintf(codeBodyStr, "beq %s, $0, End%s\n%s\nj Loop%s\nEnd%s:\n", $5.reg, label, $2.body, label, label);
 sprintf(str,"Loop%s:\n",label);
 strcat(str, $5.codeBody);
 
 $$.head = StrCat($5.codeHead, $2.head);
 $$.body = StrCat(str,codeBodyStr);
 freeTreg($5.reg);
 free(str);
 free(codeBodyStr);
}

| switch

{
 printf("CONTROL_STMT -> switch \n");
 $$.head = strdup($1.codeHead);
 $$.body = strdup($1.codeBody);
}
;	 

STMT_BLOCK: '{' STMTLIST '}'

{
 printf("STMT_BLOCK -> '{' STMTLIST '}' \n");
 $$.head = strdup($2.head);
 $$.body = strdup($2.body);
}
;

switch: SWITCH '(' CHOICE ')' '{' CASES '}'

{
 printf("switch -> SWITCH '(' CHOICE ')' '{' CASES '}' \n");
 $$.codeBody = StrCat($3.codeBody, $6.codeBody);
 $$.codeHead = StrCat($3.codeHead, $6.codeHead);
}
;

CHOICE: ID

{
 printf("CHOICE -> ID \n");
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* reg;
 symbol* sym = findInSymbolT($1);
 codeBodyStr[0]='\0';
 
 if(strcmp(sym->type, "int") == 0)
 {
  sprintf(codeBodyStr, "lw $s1,%s\n", $1);
 }
 else
 {
  reg = getFreg();
  sprintf(codeBodyStr, "l.s %s,%s\n", reg, $1);
 }
 
 $$.codeHead = strdup("");
 $$.codeBody = strdup(codeBodyStr);
 free(codeBodyStr);
}

| NUM

{
 printf("CHOICE -> NUM \n");
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* codeHeadStr = (char*)malloc(sizeof(char) * 100);
 char* reg;
 codeBodyStr[0]='\0';
 codeHeadStr[0]='\0';
 
 if(strcmp($1.type, "int") == 0)
 {
  sprintf(codeBodyStr, "li $s1,%d\n", $1.val);
 }
 else
 {
  reg = getFreg();
  char* label = getLabel();
  
  sprintf(codeHeadStr,"%s: .float %f\n", label, $1.val);
  sprintf(codeBodyStr, "l.s %s,%s\n", reg, label);
 }
 
 $$.codeHead = strdup(codeHeadStr);
 $$.codeBody = strdup(codeBodyStr);
 free(codeBodyStr);
 free(codeHeadStr);
}
;

CASES: CASE NUM ':' STMTLIST BREAK ';' CASES 

{
 printf("CASES -> CASE NUM ':' STMTLIST BREAK ';' CASES \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * (100 + strlen($4.body)));
 codeBodyStr[0]='\0';
 
 char* label = getLabel();
 char* reg=  getTreg();
 
 sprintf(codeBodyStr, "li %s, %d\nbne %s, $s1 ,next%s\n%s\nj end%s\nnext%s:\n", reg, $2.val.ival, reg, label, $4.body, $7.label,label);	
 $$.label = $7.label;
 
 $$.codeHead = StrCat($4.head, $7.codeHead);
 $$.codeBody = StrCat(codeBodyStr, $7.codeBody);
 freeTreg(reg);
 free(codeBodyStr);
}

| DEFAULT ':' STMTLIST

{
 printf("CASES -> DEFAULT ':' STMTLIST \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * (100 + strlen($3.body)));
 codeBodyStr[0]='\0';
 
 char* label = getLabel();
 sprintf(codeBodyStr, "default%s:\n%s\nend%s:", label, $3.body, label);
 
 $$.label = strdup(label);
 $$.codeHead = strdup($3.head);
 $$.codeBody = strdup(codeBodyStr);
 free(codeBodyStr);
}
;

STEP: ID ASSIGNOP ID ADDOP NUM

{
 printf("STEP -> ID ASSIGNOP ID ADDOP NUM \n");
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 codeBodyStr[0]='\0';
 
 symbol* sym1 = findInSymbolT($1);
 symbol* sym2 = findInSymbolT($3);
 
 if(strcmp(sym1->type, "int") == 0 && strcmp(sym2->type, "int") == 0 && strcmp($5.type, "int") == 0)
 {
  char* reg = getTreg();
  if($4==PLUS)
  {
	  sprintf(codeBodyStr, "lw, %s, %s\naddi %s, %s ,%d\nsw %s, %s\n", reg, $3, reg, reg, $5.val, reg, $1);
  }
  else
  {
	  sprintf(codeBodyStr, "lw, %s, %s\nsubi %s, %s ,%d\nsw %s, %s\n", reg, $3, reg, reg, $5.val, reg, $1);
  }
    
  freeTreg(reg);
 }
 
 if(strcmp(sym1->type,"float") == 0 && strcmp(sym2->type,"float") == 0 && strcmp($5.type,"float") == 0)
 {
  char* reg = getFreg();
  if($4==PLUS)
  {
	  sprintf(codeBodyStr, "l.s, %s, %s\nadd.s %s, %s ,%d\ns.s %s, %s\n", reg, $3, reg, reg, $5.val, reg, $1);
  }
  else
  {
	  sprintf(codeBodyStr, "l.s, %s, %s\nsub.s %s, %s ,%d\ns.s %s, %s\n", reg, $3, reg, reg, $5.val, reg, $1);
  }
    
  freeFreg(reg);																	 
 }
 
 $$.head = strdup("");
 $$.body = strdup(codeBodyStr);
 free(codeBodyStr);
}

| ID ASSIGNOP ID MULOP NUM

{
 printf("STEP -> ID ASSIGNOP ID MULOP NUM \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 codeBodyStr[0]='\0';
 
 symbol* sym1 = findInSymbolT($1);
 symbol* sym2 = findInSymbolT($3);
 
 if(strcmp(sym1->type, "int") == 0 && strcmp(sym2->type, "int") == 0 && strcmp($5.type, "int") == 0)
 {
  char* reg = getTreg();
  if($4==MUL)
  {
	  sprintf(codeBodyStr, "la ,%s, %s\nmul %s, %s ,%d\nsw %s, %s\n", reg, $3, reg, reg, $5.val, reg, $1);
  }
  else
  {
	  sprintf(codeBodyStr, "la ,%s, %s\ndiv %s, %s ,%d\nsw %s, %s\n", reg, $3, reg, reg, $5.val, reg, $1);
  }
    
  freeTreg(reg);
 }
 
 if(strcmp(sym1->type,"float") == 0 && strcmp(sym2->type,"float") == 0 && strcmp($5.type,"float") == 0)
 {
  char* reg = getFreg();
  if($4==MUL)
  {
	  sprintf(codeBodyStr, "l.s, %s, %s\nmul.s %s, %s ,%d\ns.s %s, %s\n", reg, $3, reg, reg, $5.val, reg, $1);
  }
  else
  {
	  sprintf(codeBodyStr, "l.s, %s, %s\ndiv.s %s, %s ,%d\ns.s %s, %s\n", reg, $3, reg, reg, $5.val, reg, $1);
  }
    
  freeFreg(reg);																	 
 }
 
 $$.head = strdup("");
 $$.body = strdup(codeBodyStr);
 free(codeBodyStr);
}
;

BOOLEXPR: BOOLEXPR OROP BOOLTERM 

{
 printf("BOOLEXPR -> BOOLEXPR OROP BOOLTERM  \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* tmp;
 codeBodyStr[0]='\0';
 
 char* reg = getTreg();
 char* label = getLabel();
 sprintf(codeBodyStr, "bne %s, %s, else%s\nadd %s, $0, %s\nj end%s\nelse%s: addi %s, $0, 1\nend%s", $1.reg, $3.reg, label, reg, $1.reg, label,label, reg, label);
 
 $$.reg = strdup(reg);
 tmp = StrCat($1.codeBody, $3.codeBody);
 
 $$.codeBody= StrCat(tmp,codeBodyStr);
 $$.codeHead= StrCat($1.codeHead, $3.codeHead);
 freeTreg($1.reg);
 freeTreg($3.reg);
 free(tmp);
 free(codeBodyStr);
}

| BOOLTERM

{
 printf("BOOLEXPR -> BOOLTERM \n");
 $$.reg = strdup($1.reg);
 $$.codeBody= strdup($1.codeBody);
 $$.codeHead= strdup($1.codeHead);
}
;

BOOLTERM: BOOLTERM ANDOP BOOLFACTOR

{
 printf("BOOLTERM -> BOOLTERM ANDOP BOOLFACTOR \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* tmp;
 codeBodyStr[0]='\0';
 
 char* reg = getTreg();
 sprintf(codeBodyStr, "mul %s, %s, %s\n", reg, $1.reg, $3.reg);
 
 $$.reg = strdup(reg);
 tmp = StrCat($1.codeBody, $3.codeBody);
 
 $$.codeBody= StrCat(tmp,codeBodyStr);
 $$.codeHead= StrCat($1.codeHead, $3.codeHead);
 freeTreg($1.reg);
 freeTreg($3.reg);
 free(tmp);
 free(codeBodyStr);
}

| BOOLFACTOR

{
 printf("BOOLTERM -> BOOLFACTOR \n");
 $$.reg = strdup($1.reg);
 $$.codeBody= strdup($1.codeBody);
 $$.codeHead= strdup($1.codeHead);
}
;

BOOLFACTOR: '!' '(' BOOLFACTOR ')'

{
 printf("BOOLFACTOR -> '!' '(' BOOLFACTOR ')' \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* reg = getTreg();
 codeBodyStr[0]='\0';
 
 sprintf(codeBodyStr, "li %s ,1\nsub %s, %s, %s\n", reg, $3.reg, reg, $3.reg);
 $$.reg= $3.reg;
 
 $$.codeBody= StrCat($3.codeBody,codeBodyStr);
 $$.codeHead= $3.codeHead;
 freeTreg(reg);
 free(codeBodyStr);
}

| EXPRESSION  RELOP  EXPRESSION

{
 printf("BOOLFACTOR -> EXPRESSION  RELOP  EXPRESSION \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 codeBodyStr[0]='\0';
 
 char* tmpBody =(char*)malloc(sizeof(char) * 100);
 char* tmpHead =(char*)malloc(sizeof(char) * 100);
 tmpBody[0]='\0';
 tmpHead[0]='\0';
 
 char* reg = getTreg();
 
 if(strcmp($1.type, "int") == 0 && strcmp($3.type, "int") == 0)
 {
  if($2==EQ)
  {
	  sprintf(codeBodyStr, "seq %s, %s, %s\n", reg, $1.reg, $3.reg);
  }
  if($2==NEQ)
  {
	  sprintf(codeBodyStr, "sne %s, %s, %s\n", reg, $1.reg, $3.reg);
  }
  if($2==LT)
  {
	  sprintf(codeBodyStr, "slt %s, %s, %s\n", reg, $1.reg, $3.reg);
  }
  if($2==GT)
  {
	  sprintf(codeBodyStr, "sgt %s, %s, %s\n", reg, $1.reg, $3.reg);
  }
  if($2==LTEQ)
  {
	  sprintf(codeBodyStr, "sle %s, %s, %s\n", reg, $1.reg, $3.reg);
  }
  if($2==GTEQ)
  {
	  sprintf(codeBodyStr, "sge %s, %s, %s\n", reg, $1.reg, $3.reg);
  }
  
  freeTreg($1.reg);
  freeTreg($3.reg);			
 }
 
 if(strcmp($1.type,"float") == 0 && strcmp($3.type,"float") == 0)
 {
  char* label = getLabel();
  if($2==EQ)
  {
	  sprintf(codeBodyStr, "c.eq.s %s, %s\nbc1f else%s\naddi %s, $0,1\nj end%s\nelse%s: move %s, $0\nend%s:\n", $1.reg, $3.reg, label, reg, label,label, reg, label);
  }
  if($2==NEQ)
  {
	  sprintf(codeBodyStr, "c.eq.s %s, %s\nbc1t else%s\naddi %s, $0,1\nj end%s\nelse%s: move %s, $0\nend%s:\n", $1.reg, $3.reg, label, reg, label,label, reg, label);
  }
  if($2==LT)
  {
	  sprintf(codeBodyStr, "c.lt.s %s, %s\nbc1t else%s\naddi %s, $0,1\nj end%s\nelse%s: move %s, $0\nend%s:\n", $3.reg, $1.reg, label, reg, label,label, reg, label);
  }
  if($2==GT)
  {
	  sprintf(codeBodyStr, "c.lt.s %s, %s\nbc1t else%s\naddi %s, $0,1\nj end%s\nelse%s: move %s, $0\nend%s:\n", $1.reg, $3.reg, label, reg, label,label, reg, label);
  }
  if($2==LTEQ)
  {
	  sprintf(codeBodyStr, "c.le.s %s, %s\nbc1t else%s\naddi %s, $0,1\nj end%s\nelse%s: move %s, $0\nend%s:\n", $3.reg, $1.reg, label, reg, label,label, reg, label);
  }
  if($2==GTEQ)
  {
	  sprintf(codeBodyStr, "c.le.s %s, %s\nbc1t else%s\naddi %s, $0,1\nj end%s\nelse%s: move %s, $0\nend%s:\n", $1.reg, $3.reg, label, reg, label,label, reg, label);
  }
  
  freeFreg($1.reg);
  freeFreg($3.reg);
 }
 
 $$.reg = strdup(reg);
 strcat(tmpBody, $1.codeBody);
 strcat(tmpBody, $3.codeBody);
 strcat(tmpBody,codeBodyStr);
 strcat(tmpHead, $1.codeHead);
 strcat(tmpHead, $3.codeHead);
 
 $$.codeBody = strdup(tmpBody);
 $$.codeHead = strdup(tmpHead);
 free(tmpBody);
 free(tmpHead);
 free(codeBodyStr);
}
;  

EXPRESSION: EXPRESSION  ADDOP  TERM 

{
 printf("EXPRESSION -> EXPRESSION  ADDOP  TERM \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* tmp;
 codeBodyStr[0]='\0';
 
 if(strcmp($1.type, "int") == 0 && strcmp($3.type, "int") == 0)
 {
  if($2 == PLUS)
  {
    sprintf(codeBodyStr, "add %s, %s ,%s\n", $3.reg, $3.reg, $1.reg);
  }
  else
  {
    sprintf(codeBodyStr, "sub %s, %s ,%s\n", $3.reg, $1.reg, $3.reg);
  }
  
  freeTreg($1.reg);
  $$.type = strdup("int");
  $$.reg = strdup($3.reg);
 }
 if(strcmp($1.type,"float") == 0 && strcmp($3.type, "int") == 0)
 {
  char* reg = getFreg();
  if($2 == PLUS)
  {
    sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\nadd.s %s, %s ,%s\n", $3.reg, reg, reg, reg, $1.reg, $1.reg, reg);
  }
  else
  {
    sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\nsub.s %s, %s ,%s\n", $3.reg, reg, reg, reg, $1.reg, $1.reg, reg);
  }
  
  freeFreg(reg);
  freeTreg($3.reg);
  $$.type = strdup("float");
  $$.reg = strdup($1.reg);
 }
 
 if(strcmp($1.type, "int") == 0 && strcmp($3.type,"float") == 0)
 {
  char* reg = getFreg();
  if($2 == PLUS)
  {
    sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\nadd.s %s, %s ,%s\n", $1.reg, reg, reg, reg, $3.reg, $3.reg, reg);
  }
  else
  {
    sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\nsub.s %s, %s ,%s\n", $1.reg, reg, reg, reg, $3.reg, reg, $3.reg);
  }
  
  freeFreg(reg);
  freeTreg($1.reg);
  $$.type = strdup("float");
  $$.reg = strdup($3.reg);
 }
 
 if(strcmp($1.type,"float") == 0 && strcmp($3.type,"float") == 0)
 {
  if($2 == PLUS)
  {
    sprintf(codeBodyStr, "add.s %s, %s ,%s\n", $3.reg, $1.reg, $3.reg);
  }
  else
  {
    sprintf(codeBodyStr, "sub.s %s, %s ,%s\n", $3.reg, $1.reg, $3.reg);
  }
  
  freeFreg($1.reg);
  $$.type = strdup("float");
  $$.reg = strdup($3.reg);
 }
 
 tmp = StrCat($1.codeBody, $3.codeBody);

 $$.codeBody= StrCat(tmp,codeBodyStr);
 $$.codeHead= StrCat($1.codeHead, $3.codeHead);
 free(tmp);
 free(codeBodyStr);
}

| TERM

{
 printf("EXPRESSION -> TERM \n");
 $$.reg =  strdup($1.reg);
 $$.codeBody = strdup($1.codeBody);
 $$.codeHead = strdup($1.codeHead);
 $$.type = strdup($1.type);
}
;

TERM: TERM MULOP FACTOR 

{
 printf("TERM -> TERM MULOP FACTOR \n");
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* tmp;
 codeBodyStr[0]='\0';
 
 if(strcmp($1.type, "int") == 0 && strcmp($3.type, "int") == 0)
 {
  if($2 == MUL) 
  {
    sprintf(codeBodyStr, "mul %s, %s ,%s\n", $3.reg, $3.reg, $1.reg);
  }
  else
  {
    sprintf(codeBodyStr, "div %s, %s ,%s\n", $3.reg, $3.reg, $1.reg);
  }
  
  freeTreg($1.reg);
  $$.type = strdup("int");
  $$.reg = strdup($3.reg);
 }
 if(strcmp($1.type,"float") == 0 && strcmp($3.type, "int") == 0)
 {
  char* reg = getFreg();
  if($2 == MUL) 
  {
    sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\nmul.s %s, %s ,%s\n", $3.reg, reg, reg, reg, $1.reg, $1.reg, reg);
  }
  else
  {
    sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\ndiv.s %s, %s ,%s\n", $3.reg, reg, reg, reg, $1.reg, $1.reg, reg);
  }
  
  freeFreg(reg);
  freeTreg($3.reg);
  $$.type = strdup("float");
  $$.reg = strdup($1.reg);
 }
 
 if(strcmp($1.type, "int") == 0 && strcmp($3.type,"float") == 0)
 {
  char* reg = getFreg();
  if($2 == MUL) 
  {
    sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\nmul.s %s, %s ,%s\n", $1.reg, reg, reg, reg, $3.reg, $3.reg, reg);
  }
  else
  {
    sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\ndiv.s %s, %s ,%s\n", $1.reg, reg, reg, reg, $3.reg, $3.reg, reg);
  }
  
  freeFreg(reg);
  freeTreg($1.reg);
  $$.type = strdup("float");
  $$.reg = strdup($3.reg);
 }
 if(strcmp($1.type,"float") == 0 && strcmp($3.type,"float") == 0)
 {
  if($2 == MUL)
  {
    sprintf(codeBodyStr, "mul.s %s, %s ,%s\n", $3.reg, $3.reg, $1.reg);
  }
  else
  {
    sprintf(codeBodyStr, "div.s %s, %s ,%s\n", $3.reg, $3.reg, $1.reg);
  }
  
  freeFreg($1.reg);
  $$.type = strdup("float");
  $$.reg = strdup($3.reg);
 }			
 
 tmp = StrCat($1.codeBody, $3.codeBody);
 
 $$.codeBody= StrCat(tmp,codeBodyStr);
 $$.codeHead= StrCat($1.codeHead, $3.codeHead);
 free(tmp);
 free(codeBodyStr);
} 

| FACTOR 

{
 printf("TERM -> FACTOR \n");
 $$.reg =  strdup($1.reg);
 $$.codeBody = strdup($1.codeBody);
 $$.codeHead = strdup($1.codeHead);
 $$.type = strdup($1.type);
}
;

FACTOR: '(' EXPRESSION ')' 

{
 printf("FACTOR -> '(' EXPRESSION ')' \n");
 $$.reg =  strdup($2.reg);
 $$.codeBody = strdup($2.codeBody);
 $$.codeHead = strdup($2.codeHead);
 $$.type = strdup($2.type);
} 

| NUM 

{
 printf("FACTOR -> NUM \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* codeHeadStr = (char*)malloc(sizeof(char) * 100);
 char* reg;
 codeBodyStr[0]='\0';
 codeHeadStr[0]='\0';
 
 if(strcmp($1.type, "int") == 0)
 {
  reg = getTreg();
  sprintf(codeBodyStr, "addi %s, $0, %d\n", reg, $1.val.ival);
 }
 else
 {
  reg = getFreg();
  char* label = getLabel();
  sprintf(codeHeadStr,"%s: .float %f\n",label, $1.val.fval);
  sprintf(codeBodyStr, "l.s %s, %s\n", reg, label);
 }
 
 $$.type = strdup($1.type);
 $$.reg = strdup(reg);
 
 $$.codeHead = strdup(codeHeadStr);
 $$.codeBody = strdup(codeBodyStr);
 free(codeHeadStr);
 free(codeBodyStr);
}

| ID

{
 printf("FACTOR -> ID \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* reg;
 char* label = getLabel();
 codeBodyStr[0]='\0';
 
 symbol* sym = findInSymbolT($1);
 
 if(sym !=NULL)
 {
  if(strcmp(sym->type, "int") == 0)
  {
   reg = getTreg();
   sprintf(codeBodyStr, "lw %s, %s\n", reg, $1);
  }
  if(strcmp(sym->type,"float") == 0)
  {
   reg = getFreg();
   sprintf(codeBodyStr, "l.s %s, %s\n", reg, $1);
  }
  if(strcmp(sym->type,"string") == 0)
  {
   reg= $1;
  }
  
  $$.reg = strdup(reg);
  $$.type = strdup(sym->type);
  $$.codeBody = strdup(codeBodyStr);
  $$.codeHead=strdup("");
 }
}
;

%%

int main (int argc, char **argv)
{
	int counter = 1;
	char line[500];

	FILE *errorList,*mips;
	extern FILE *yyin;

	printf("Students:  Matan Cohen, Ori Ashkenazi\n");
	
	
	yyin = fopen(argv[1],"r");
	errorList = fopen("errors.LST","w+");

	fprintf(errorList,"ERRORLOG ORI&MATAN COMPILER\n");
	printf("code copy to error file\n");
	do{
		fgets(line, 500, yyin);
		fprintf(errorList,"%d: %s", counter, line);
		counter++;
	} while (!feof(yyin));
	
	fclose(errorList);
	
	
	printf("pars\n");
	fseek(yyin, 0, SEEK_SET);
	yyparse();
	fclose(yyin);
	
	
	if(isError == 1)
	{
		errorList = fopen("errors.LST", "a+");
		fprintf(errorList,"No Errors found. Good Job!\n");
		mips = fopen("MIPS.S","w+");
		fprintf(mips,"%s", mipsCod);
		fclose(mips);	
		fclose(errorList);
	}
	else
	{
		printf("error!\n");
	}
	return 0;
}

int sentLabelNum =0;
symbol* headSymTbl = NULL;												
char* registerT[8] = {"$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7"};
char* registerF[8] = {"$f0","$f1","$f2","$f3","$f4","$f5","$f6","$f7"};
int IndexRegT=0;
int IndexRegF=0;

symbol* insertToTable (char* name, char *type, int isconst)
{
	symbol* newSym = (symbol*)malloc(sizeof(symbol));
	newSym->name = strdup(name);
	newSym->type = strdup(type);
	newSym->init = 0;
	newSym->isconst = isconst;
	
	if (headSymTbl != NULL)
	{
		newSym->next = headSymTbl;
	}
	else
	{
		newSym->next = NULL;
	}
	headSymTbl = newSym;
	
	return newSym;
}

symbol* findInSymbolT(char* name)
{
	symbol* ptr = headSymTbl;
	while (ptr != NULL)
	{
		if (strcmp(ptr->name,name) == 0)
		{
			return ptr;
		}
		ptr = ptr->next;
	}
	
	return NULL;
}

char* StrCat(char* char1, char* char2)
{
	char* str =(char*)malloc(sizeof(char) * (strlen(char1) + strlen(char2) + 1));
	str[0]='\0';
	
	strcat(str,char1);
	strcat(str,char2);
	return str;
}

char* getLabel()
{
	char str[100];
	sprintf(str,"Label%d", sentLabelNum);
	sentLabelNum++;
	
	return strdup(str);
}

char* getTreg()
{
	char* res;
	res = registerT[IndexRegT];
	IndexRegT++;
	
	return res;
}
void freeTreg(char* reg)
{
	IndexRegT--;
	registerT[IndexRegT] = reg;
}

char* getFreg()
{
	char* res;
	res = registerF[IndexRegF];
	IndexRegF++;

	return res;
}

void freeFreg(char* reg)
{
	IndexRegF--;
	registerF[IndexRegF] = reg;
}

void outputError(char* s){
     FILE* list;
     list = fopen("errors.LST","a+");
     fprintf(list,"ERROR line: %d, column: %d: %s\n",yylineno,column,s);
     fclose(list);
}

void yyerror(char* s) {}