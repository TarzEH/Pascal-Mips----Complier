/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     SENTENCE = 259,
     ADDOP = 260,
     MULOP = 261,
     ASSIGNOP = 262,
     OROP = 263,
     ANDOP = 264,
     RELOP = 265,
     NUM = 266,
     BREAK = 267,
     CASE = 268,
     DEFAULT = 269,
     DO = 270,
     ELSE = 271,
     END = 272,
     INT = 273,
     PROGRAM = 274,
     REAL = 275,
     READ = 276,
     BGN = 277,
     STRING = 278,
     SWITCH = 279,
     TILL = 280,
     VAR = 281,
     IF = 282,
     WHILE = 283,
     LET = 284,
     FINAL = 285,
     OUT = 286,
     WITH = 287,
     FOREACH = 288
   };
#endif
/* Tokens.  */
#define ID 258
#define SENTENCE 259
#define ADDOP 260
#define MULOP 261
#define ASSIGNOP 262
#define OROP 263
#define ANDOP 264
#define RELOP 265
#define NUM 266
#define BREAK 267
#define CASE 268
#define DEFAULT 269
#define DO 270
#define ELSE 271
#define END 272
#define INT 273
#define PROGRAM 274
#define REAL 275
#define READ 276
#define BGN 277
#define STRING 278
#define SWITCH 279
#define TILL 280
#define VAR 281
#define IF 282
#define WHILE 283
#define LET 284
#define FINAL 285
#define OUT 286
#define WITH 287
#define FOREACH 288



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 44 "CPM.y"

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


/* Line 2058 of yacc.c  */
#line 155 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
