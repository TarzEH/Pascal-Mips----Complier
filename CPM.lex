%{
	#include<stdio.h>
	#include<malloc.h>
	#include<string.h>
	#include "y.tab.h"
	extern int atoi (const char *);
	static int next_column = 1;
        int column = 1;
        #define HANDLE_COLUMN column = next_column; next_column += strlen(yytext)
%}
%option noyywrap yylineno 
digit [0-9]
letter [a-zA-Z]
%%
"break" {HANDLE_COLUMN; return BREAK;}
"case" {HANDLE_COLUMN; return CASE;}
"default" {HANDLE_COLUMN; return DEFAULT;}
"do" {HANDLE_COLUMN; return DO;}
"else" {HANDLE_COLUMN; return ELSE;}
"end" {HANDLE_COLUMN; return END;}
"if" {HANDLE_COLUMN; return IF;}
"int" {HANDLE_COLUMN; return INT;}
"program" {HANDLE_COLUMN; return PROGRAM;}
"final" {HANDLE_COLUMN; return FINAL;}
"out" {HANDLE_COLUMN; return OUT;}
"real" {HANDLE_COLUMN; return REAL;}
"read" {HANDLE_COLUMN; return READ;}
"bgn" {HANDLE_COLUMN; return BGN;}
"string" {HANDLE_COLUMN; return STRING;}
"switch" {HANDLE_COLUMN; return SWITCH;}
"till" {HANDLE_COLUMN; return TILL;}
"var" {HANDLE_COLUMN; return VAR;}
"let" {HANDLE_COLUMN; return LET;}
"while" {HANDLE_COLUMN; return WHILE;}
"with" {HANDLE_COLUMN; return WITH;}
"foreach" {HANDLE_COLUMN; return FOREACH;}


"(" {HANDLE_COLUMN; return '(';}
")" {HANDLE_COLUMN; return ')';}
"{" {HANDLE_COLUMN; return '{';}
"}" {HANDLE_COLUMN; return '}';}
"," {HANDLE_COLUMN; return ',';}
":" {HANDLE_COLUMN; return ':';}
";" {HANDLE_COLUMN; return ';';}
"!" {HANDLE_COLUMN; return '!';}
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] { /* DO NOTHING */ }
\"([a-zA-Z|.|,|!|?|" "|0-9])*\" {HANDLE_COLUMN; yylval.sval = (char*) malloc(yyleng * sizeof(char)); strcpy(yylval.sval, yytext);return SENTENCE;}
{digit}+ {HANDLE_COLUMN; yylval.number.val.ival=atoi(yytext);yylval.number.type = strdup("int");return NUM;}
{digit}+"."{digit}* {HANDLE_COLUMN; yylval.number.val.fval=atof(yytext);yylval.number.type = strdup("float");return NUM;}
{letter}({letter}|{digit}){0,8} {HANDLE_COLUMN; yylval.sval = (char*) malloc(yyleng * sizeof(char)); strcpy(yylval.sval, yytext);return ID;}
"==" {HANDLE_COLUMN; yylval.op=EQ;return RELOP;}
"<>" {HANDLE_COLUMN; yylval.op=NEQ;return RELOP;}
"<"  {HANDLE_COLUMN; yylval.op=LT;return RELOP;}
">"  {HANDLE_COLUMN; yylval.op=GT;return RELOP;}
">=" {HANDLE_COLUMN; yylval.op=GTEQ;return RELOP;}
"<=" {HANDLE_COLUMN; yylval.op=LTEQ;return RELOP;}
"+"  {HANDLE_COLUMN; yylval.op=PLUS;return ADDOP;}
"-"  {HANDLE_COLUMN; yylval.op=MINUS;return ADDOP;}
"*"  {HANDLE_COLUMN; yylval.op=MUL;return MULOP;}
"/"  {HANDLE_COLUMN; yylval.op=DIV;return MULOP;}
":=" {HANDLE_COLUMN; yylval.op=ASSIGN;return ASSIGNOP;}
"||" {HANDLE_COLUMN; yylval.op=OR;return OROP;}
"&&" {HANDLE_COLUMN; yylval.op=AND;return ANDOP;}
"/*".*"*/"
[\n] {HANDLE_COLUMN; next_column = 1;}
%%