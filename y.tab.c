/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "CPM.y"

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

/* Line 371 of yacc.c  */
#line 109 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
/* Line 387 of yacc.c  */
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


/* Line 387 of yacc.c  */
#line 250 "y.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 291 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   208

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  183

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,     2,     2,     2,     2,     2,
      37,    38,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,    36,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    14,    15,    18,    20,    24,    28,
      31,    33,    35,    37,    45,    46,    49,    50,    52,    57,
      59,    61,    63,    65,    71,    77,    78,    85,    86,    93,
      94,   101,   107,   112,   120,   121,   130,   131,   140,   141,
     150,   156,   157,   164,   165,   172,   173,   180,   192,   204,
     211,   213,   217,   225,   227,   229,   237,   241,   247,   253,
     257,   259,   263,   265,   270,   274,   278,   280,   284,   286,
     290,   292
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    19,     3,    22,    44,    50,    17,    -1,
      29,    45,    49,    -1,    -1,    45,    46,    -1,    46,    -1,
      48,    34,    47,    -1,     3,    35,    47,    -1,     3,    36,
      -1,    18,    -1,    20,    -1,    23,    -1,    30,    48,     3,
       7,    11,    36,    49,    -1,    -1,    50,    51,    -1,    -1,
      57,    -1,     3,     7,     4,    36,    -1,    58,    -1,    56,
      -1,    52,    -1,    65,    -1,    31,    37,    73,    38,    36,
      -1,    31,    37,     4,    38,    36,    -1,    -1,    31,    53,
       1,     4,    38,    36,    -1,    -1,    31,    37,     4,    54,
       1,    36,    -1,    -1,    31,    37,     4,    38,    55,     1,
      -1,    21,    37,     3,    38,    36,    -1,     3,     7,    73,
      36,    -1,    27,    37,    70,    38,    51,    16,    51,    -1,
      -1,    27,    59,     1,    70,    38,    51,    16,    51,    -1,
      -1,    27,    37,     1,    60,    38,    51,    16,    51,    -1,
      -1,    27,    37,    70,    61,     1,    51,    16,    51,    -1,
      28,    37,    70,    38,    65,    -1,    -1,    28,    62,     1,
      70,    38,    65,    -1,    -1,    28,    37,     1,    63,    38,
      65,    -1,    -1,    28,    37,    70,    64,     1,    65,    -1,
      33,     3,    36,     7,    36,    11,    34,    11,    32,    69,
      51,    -1,    33,     3,    36,     7,    36,    11,    34,     3,
      32,    69,    51,    -1,    15,    65,    25,    37,    70,    38,
      -1,    66,    -1,    39,    50,    40,    -1,    24,    37,    67,
      38,    39,    68,    40,    -1,     3,    -1,    11,    -1,    13,
      11,    34,    50,    12,    36,    68,    -1,    14,    34,    50,
      -1,     3,     7,     3,     5,    11,    -1,     3,     7,     3,
       6,    11,    -1,    70,     8,    71,    -1,    71,    -1,    71,
       9,    72,    -1,    72,    -1,    41,    37,    72,    38,    -1,
      73,    10,    73,    -1,    73,     5,    74,    -1,    74,    -1,
      74,     6,    75,    -1,    75,    -1,    37,    73,    38,    -1,
      11,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,   103,   113,   120,   127,   135,   180,   204,
     221,   228,   235,   243,   283,   290,   299,   307,   315,   369,
     377,   384,   392,   401,   424,   444,   444,   451,   451,   458,
     458,   466,   513,   575,   595,   595,   602,   602,   609,   609,
     616,   638,   638,   645,   645,   652,   652,   659,   664,   670,
     692,   701,   710,   719,   743,   773,   793,   811,   856,   903,
     927,   937,   960,   970,   988,  1081,  1165,  1176,  1258,  1269,
    1279,  1312
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "SENTENCE", "ADDOP", "MULOP",
  "ASSIGNOP", "OROP", "ANDOP", "RELOP", "NUM", "BREAK", "CASE", "DEFAULT",
  "DO", "ELSE", "END", "INT", "PROGRAM", "REAL", "READ", "BGN", "STRING",
  "SWITCH", "TILL", "VAR", "IF", "WHILE", "LET", "FINAL", "OUT", "WITH",
  "FOREACH", "':'", "','", "';'", "'('", "')'", "'{'", "'}'", "'!'",
  "$accept", "MAIN", "DECLARATIONS", "DECLARLIST", "DECL", "LIST", "TYPE",
  "CDECL", "STMTLIST", "STMT", "OUT_STMT", "$@1", "$@2", "$@3",
  "READ_STMT", "ASSIGNMENT_STMT", "CONTROL_STMT", "$@4", "$@5", "$@6",
  "$@7", "$@8", "$@9", "STMT_BLOCK", "switch", "CHOICE", "CASES", "STEP",
  "BOOLEXPR", "BOOLTERM", "BOOLFACTOR", "EXPRESSION", "TERM", "FACTOR", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    58,    44,    59,    40,    41,   123,
     125,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    47,    47,
      48,    48,    48,    49,    49,    50,    50,    51,    51,    51,
      51,    51,    51,    52,    52,    53,    52,    54,    52,    55,
      52,    56,    57,    58,    59,    58,    60,    58,    61,    58,
      58,    62,    58,    63,    58,    64,    58,    58,    58,    58,
      58,    65,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     3,     0,     2,     1,     3,     3,     2,
       1,     1,     1,     7,     0,     2,     0,     1,     4,     1,
       1,     1,     1,     5,     5,     0,     6,     0,     6,     0,
       6,     5,     4,     7,     0,     8,     0,     8,     0,     8,
       5,     0,     6,     0,     6,     0,     6,    11,    11,     6,
       1,     3,     7,     1,     1,     7,     3,     5,     5,     3,
       1,     3,     1,     4,     3,     3,     1,     3,     1,     3,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,    16,    10,    11,
      12,    14,     6,     0,     0,     0,     5,     3,     0,     0,
       0,     2,     0,     0,    34,    41,    25,     0,    16,    15,
      21,    20,    17,    19,    22,    50,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    71,     0,    70,     0,     0,    66,
      68,     0,     0,    53,    54,     0,    36,     0,    38,    60,
      62,     0,     0,    43,    45,     0,    27,     0,     0,     0,
      51,     0,     8,    18,     0,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,     0,     0,     0,    69,
      65,    67,     0,    31,     0,     0,     0,    59,     0,     0,
      61,    64,     0,     0,    40,     0,     0,    24,     0,     0,
      23,     0,     0,    14,    49,     0,     0,     0,     0,    63,
       0,     0,     0,    44,    46,    42,    30,    28,    26,     0,
      13,     0,    16,    52,     0,    33,     0,     0,     0,    16,
      56,    37,    39,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    47,    55,     0,     0,
       0,    57,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    11,    12,    38,    13,    17,    14,    29,
      30,    48,   104,   128,    31,    32,    33,    44,    91,    95,
      46,    99,   101,    34,    35,    65,   137,   171,    68,    69,
      70,    71,    59,    60
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -93
static const yytype_int16 yypact[] =
{
      -7,    53,    60,    10,   -93,    39,    65,   -93,   -93,   -93,
     -93,    52,   -93,    55,    94,    65,   -93,   -93,    83,    85,
      56,   -93,    64,    68,    73,    75,    76,   105,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   113,    38,   -93,    15,
      92,   116,    11,     4,   119,     5,   128,    32,   129,    98,
      63,   130,    83,   -93,   -93,   100,   -93,    17,     8,   135,
     -93,   106,   107,   -93,   -93,   109,   -93,   114,     1,   139,
     -93,    88,    14,   -93,     2,    14,   117,    19,   150,   152,
     -93,   146,   -93,   -93,    33,    17,   -93,    17,    14,   124,
     122,   127,    14,    14,   125,   161,    14,    17,    21,   131,
      56,   162,    25,   132,   165,   134,   133,   136,   137,   -93,
     135,   -93,    29,   -93,    86,   125,   138,   139,   151,   125,
     -93,   169,   125,    56,   -93,    56,    56,   -93,   174,   141,
     -93,   142,   168,   153,   -93,   170,   148,   140,   171,   -93,
     125,   172,   173,   -93,   -93,   -93,   -93,   -93,   -93,   156,
     -93,   157,   -93,   -93,   125,   -93,   125,   125,    47,   -93,
     125,   -93,   -93,   -93,   154,   160,   111,   181,   181,   149,
     186,   125,   125,    86,   191,   -93,   -93,   -93,    71,   184,
     185,   -93,   -93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   -93,   -93,   187,   145,   188,    66,   -28,   -92,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -19,   -93,   -93,    27,    34,   -41,   108,
     -43,   -36,   120,   121
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      50,    40,   118,    58,    74,    66,    73,    54,    54,    93,
      93,    77,     1,    85,    63,    56,    56,    54,    54,    55,
      54,    84,    64,   138,    85,    56,    56,   141,    56,    93,
     142,    98,     5,    93,   102,    54,    76,    93,    85,    94,
     100,    57,    57,    56,    86,    67,    67,   112,   155,   116,
     164,    57,    57,   120,    57,    67,     3,   105,   165,   122,
       4,   121,   161,   126,   162,   163,    19,   134,     6,    57,
       8,   109,     9,    52,    53,    10,   179,   180,    20,   175,
     176,   124,    15,     8,    22,     9,    37,    23,    10,    18,
      24,    25,    39,    85,    26,    28,    27,    19,    97,   135,
     136,    41,    28,    80,   143,    42,   144,   145,    49,    20,
      43,    21,    45,    47,    19,    22,    51,    61,    23,    62,
      72,    24,    25,   169,   160,    26,    20,    27,    19,    75,
      78,   166,    22,    28,    79,    23,    83,    81,    24,    25,
      20,    87,    26,    88,    27,    89,    22,    90,    96,    23,
      28,    92,    24,    25,   106,   103,    26,   108,    27,   107,
     113,   114,   119,   125,    28,   115,   129,   140,   127,   123,
     130,   131,   132,   133,    85,   146,   139,   147,   148,   149,
     153,   151,   152,    15,   170,   173,   167,   154,   156,   157,
     158,   159,   168,   174,   178,   181,   182,    82,    16,   150,
     177,   117,   172,    36,     0,   110,     0,     0,   111
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-93)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      28,    20,    94,    39,    45,     1,     1,     3,     3,     8,
       8,    47,    19,     5,     3,    11,    11,     3,     3,     4,
       3,    57,    11,   115,     5,    11,    11,   119,    11,     8,
     122,    72,    22,     8,    75,     3,     4,     8,     5,    38,
      38,    37,    37,    11,    36,    41,    41,    88,   140,    92,
       3,    37,    37,    96,    37,    41,     3,    38,    11,    38,
       0,    97,   154,    38,   156,   157,     3,    38,    29,    37,
      18,    38,    20,    35,    36,    23,     5,     6,    15,   171,
     172,   100,    30,    18,    21,    20,     3,    24,    23,    34,
      27,    28,     7,     5,    31,    39,    33,     3,    10,    13,
      14,    37,    39,    40,   123,    37,   125,   126,     3,    15,
      37,    17,    37,    37,     3,    21,     3,    25,    24,     3,
       1,    27,    28,    12,   152,    31,    15,    33,     3,     1,
       1,   159,    21,    39,    36,    24,    36,     7,    27,    28,
      15,     6,    31,    37,    33,    38,    21,    38,     9,    24,
      39,    37,    27,    28,     4,    38,    31,    11,    33,     7,
      36,    39,     1,     1,    39,    38,     1,    16,    36,    38,
      36,    38,    36,    36,     5,     1,    38,    36,    36,    11,
      40,    11,    34,    30,     3,    36,    32,    16,    16,    16,
      34,    34,    32,     7,     3,    11,    11,    52,    11,   133,
     173,    93,   168,    15,    -1,    85,    -1,    -1,    87
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    43,     3,     0,    22,    29,    44,    18,    20,
      23,    45,    46,    48,    50,    30,    46,    49,    34,     3,
      15,    17,    21,    24,    27,    28,    31,    33,    39,    51,
      52,    56,    57,    58,    65,    66,    48,     3,    47,     7,
      65,    37,    37,    37,    59,    37,    62,    37,    53,     3,
      50,     3,    35,    36,     3,     4,    11,    37,    73,    74,
      75,    25,     3,     3,    11,    67,     1,    41,    70,    71,
      72,    73,     1,     1,    70,     1,     4,    73,     1,    36,
      40,     7,    47,    36,    73,     5,    36,     6,    37,    38,
      38,    60,    37,     8,    38,    61,     9,    10,    70,    63,
      38,    64,    70,    38,    54,    38,     4,     7,    11,    38,
      74,    75,    70,    36,    39,    38,    72,    71,    51,     1,
      72,    73,    38,    38,    65,     1,    38,    36,    55,     1,
      36,    38,    36,    36,    38,    13,    14,    68,    51,    38,
      16,    51,    51,    65,    65,    65,     1,    36,    36,    11,
      49,    11,    34,    40,    16,    51,    16,    16,    34,    34,
      50,    51,    51,    51,     3,    11,    50,    32,    32,    12,
       3,    69,    69,    36,     7,    51,    51,    68,     3,     5,
       6,    11,    11
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 86 "CPM.y"
    {
 printf("MAIN -> PROGRAM ID BGN DECLARATIONS STMTLIST END \n");
 char* str = (char*)malloc(sizeof(char*) * 1000);
 str[0]='\0';
 if((yyvsp[(5) - (6)].code).head == NULL){ 
   (yyvsp[(5) - (6)].code).head="";
 }
  
 if((yyvsp[(4) - (6)].dec).codeBody == NULL) { 
	(yyvsp[(4) - (6)].dec).codeBody="";
 }
    
 sprintf(str,".data\n%s\n%s\nstrBuff: .space 200\n.text\nmain:\n%s\n%s\n", (yyvsp[(4) - (6)].dec).codeHead, (yyvsp[(5) - (6)].code).head, (yyvsp[(4) - (6)].dec).codeBody, (yyvsp[(5) - (6)].code).body);
 mipsCod = str;
}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 105 "CPM.y"
    {
 printf("DECLARATIONS -> LET  DECLARLIST CDECL\n");
 (yyval.dec).codeHead = strdup(strcat((yyvsp[(2) - (3)].dec).codeHead, (yyvsp[(3) - (3)].dec).codeHead));
 (yyval.dec).codeBody = strdup((yyvsp[(3) - (3)].dec).codeBody);
}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 113 "CPM.y"
    {
 printf("DECLARATIONS -> empty \n");
 (yyval.dec).codeHead = strdup("");
 (yyval.dec).codeBody = strdup("");
}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 122 "CPM.y"
    {
 printf("DECLARLIST -> DECLARLIST DECL \n");
 (yyval.dec).codeHead = StrCat((yyvsp[(1) - (2)].dec).codeHead, (yyvsp[(2) - (2)].dec).codeHead);
}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 129 "CPM.y"
    {
 printf("DECLARLIST -> DECL \n");
 (yyval.dec).codeHead = strdup((yyvsp[(1) - (1)].dec).codeHead);
}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 137 "CPM.y"
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
  if((yyvsp[(3) - (3)].dec).arrrray[i] != NULL)
  {
   if(findInSymbolT((yyvsp[(3) - (3)].dec).arrrray[i]) == NULL)
   {
    insertToTable((yyvsp[(3) - (3)].dec).arrrray[i], (yyvsp[(1) - (3)].dec).type, 0);
    if(strcmp((yyvsp[(1) - (3)].dec).type, "string") == 0)
    {
     sprintf(codeHeadStrTmp, "%s: .space 200\n", (yyvsp[(3) - (3)].dec).arrrray[i]);
     strcat(codeHeadStr, codeHeadStrTmp);
    }
    else
    {
     sprintf(codeHeadStrTmp, "%s: .space 8\n", (yyvsp[(3) - (3)].dec).arrrray[i]);
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
 
 (yyval.dec).codeHead = strdup(codeHeadStr);
 free(codeHeadStr);
 free(codeHeadStrTmp);
}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 182 "CPM.y"
    {
 printf("LIST -> ID ',' LIST \n");
 
 int i, j;
 for(i = 0 ; i < 5 ; i++)
 {
  if((yyval.dec).arrrray[i] == NULL)
  {
   (yyval.dec).arrrray[i] = (yyvsp[(1) - (3)].sval);
   for(j = 0 ; j < 5 ; j++)
   {
     if((yyvsp[(3) - (3)].dec).arrrray[i] != NULL)
     {
      (yyval.dec).arrrray[i+1] = (yyvsp[(3) - (3)].dec).arrrray[j];
      i++;
     }
   }
   break;
  }
 }
}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 206 "CPM.y"
    {
 printf("LIST -> ID ';' \n");
 
 int i;
 for(i = 0 ; i < 5 ; i++)
 {
  if((yyval.dec).arrrray[i] == NULL)
  {
   (yyval.dec).arrrray[i] = (yyvsp[(1) - (2)].sval);
   break;
  }
 }
}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 223 "CPM.y"
    {
 printf("TYPE -> INT \n");
 (yyval.dec).type = strdup("int");
}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 230 "CPM.y"
    {
 printf("TYPE -> REAL \n");
 (yyval.dec).type = strdup("float");
}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 237 "CPM.y"
    {
 printf("TYPE -> STRING \n");
 (yyval.dec).type = strdup("string");
}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 245 "CPM.y"
    {
 printf("CDECL -> FINAL TYPE ID ASSIGNOP NUM ';' CDECL \n");
 
 symbol* sym = NULL;  
 char* codeHeadStr = (char*)malloc(sizeof(char) * 100);
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 codeHeadStr[0] = '\0';
 codeBodyStr[0] = '\0';
 
 if(findInSymbolT((yyvsp[(3) - (7)].sval)) == NULL)
 {
  sym = insertToTable((yyvsp[(3) - (7)].sval), (yyvsp[(2) - (7)].dec).type, 1);
  if(strcmp((yyvsp[(2) - (7)].dec).type, "string") == 0)
  {
	  sprintf(codeHeadStr,"%s: .space 200\n", (yyvsp[(3) - (7)].sval));
  }
  else
  {
   sprintf(codeHeadStr, "%s: .space 8\n", (yyvsp[(3) - (7)].sval));
   if(strcmp((yyvsp[(2) - (7)].dec).type, "int") == 0)
   {
	   sprintf(codeBodyStr, "li $t0,%d\nsw $t0, %s\n", (yyvsp[(5) - (7)].number).val, (yyvsp[(3) - (7)].sval));  
   }
  }
 }
 else
 {
  outputError("Double declaration. Already declared.");
  sprintf(codeHeadStr,"");
  isError = 0;
 }
 
 (yyval.dec).codeHead = StrCat(codeHeadStr, (yyvsp[(7) - (7)].dec).codeHead);
 (yyval.dec).codeBody = StrCat(codeBodyStr, (yyvsp[(7) - (7)].dec).codeBody);
}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 283 "CPM.y"
    {
 printf("CDECL -> empty \n");
 (yyval.dec).codeHead = strdup("");
 (yyval.dec).codeBody = strdup("");
}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 292 "CPM.y"
    {
 printf("STMTLIST -> STMTLIST STMT \n");
 (yyval.code).body = StrCat((yyvsp[(1) - (2)].code).body, (yyvsp[(2) - (2)].code).body);
}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 299 "CPM.y"
    {
 printf("STMTLIST -> EMPTY \n");
 (yyval.code).head = strdup("");
 (yyval.code).body = strdup("");

}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 309 "CPM.y"
    {
 printf("STMT -> ASSIGNMENT_STMT \n");
 (yyval.code).head = strdup((yyvsp[(1) - (1)].code).head);
 (yyval.code).body = strdup((yyvsp[(1) - (1)].code).body);
}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 317 "CPM.y"
    {
 printf("STMT -> ID ASSIGNOP SENTENCE ';' \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* codeHeadStr = (char*)malloc(sizeof(char) * 100);
 char* reg = getTreg();
 codeBodyStr[0]='\0';
 codeHeadStr[0]='\0';
 
 char* label = getLabel();
 symbol* sym = findInSymbolT((yyvsp[(1) - (4)].sval));
 
 if (sym != NULL)
 {
  if(sym->isconst == 0)
  {
   if(strcmp(sym->type,"string") == 0)
   {
    sym->strV = strdup((yyvsp[(3) - (4)].sval));
    sprintf(codeHeadStr,"%s: .asciiz %s\n", label, (yyvsp[(3) - (4)].sval));
    sprintf(codeBodyStr, "lw %s, %s\nsw %s, %s\n", reg, label, reg, (yyvsp[(1) - (4)].sval));
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
 
 (yyval.code).head = strdup(codeHeadStr);
 (yyval.code).body = strdup(codeBodyStr);
 
 free(codeHeadStr);
 free(codeBodyStr);
}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 371 "CPM.y"
    {
 printf("STMT -> CONTROL_STMT \n");
 (yyval.code).head = strdup((yyvsp[(1) - (1)].code).head);
 (yyval.code).body = strdup((yyvsp[(1) - (1)].code).body);
}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 379 "CPM.y"
    {
 printf("STMT -> READ_STMT \n");
 (yyval.code).body = strdup((yyvsp[(1) - (1)].code).body);
}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 386 "CPM.y"
    {
 printf("STMT -> OUT_STMT \n");
 (yyval.code).head = strdup((yyvsp[(1) - (1)].code).head);
 (yyval.code).body = strdup((yyvsp[(1) - (1)].code).body);
}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 394 "CPM.y"
    {
 printf("STMT -> STMT_BLOCK \n");
 (yyval.code).head = strdup((yyvsp[(1) - (1)].code).head);
 (yyval.code).body = strdup((yyvsp[(1) - (1)].code).body);
}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 403 "CPM.y"
    {
 printf("OUT_STMT -> OUT '(' EXPRESSION ')' ';' \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 codeBodyStr[0]='\0';
 
 if(strcmp((yyvsp[(3) - (5)].dec).type, "int") == 0)
 {
	 sprintf(codeBodyStr, "li $v0,1\nmove $a0,%s\n syscall\n", (yyvsp[(3) - (5)].dec).reg);
 }
  
 if(strcmp((yyvsp[(3) - (5)].dec).type,"float") == 0)
 {
	sprintf(codeBodyStr, "li $v0,2\nmov.s $f12,%s\n syscall\n", (yyvsp[(3) - (5)].dec).reg); 
 }
  
 (yyval.code).head = (yyvsp[(3) - (5)].dec).codeHead;
 (yyval.code).body = StrCat((yyvsp[(3) - (5)].dec).codeBody,codeBodyStr);
 free(codeBodyStr);
}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 426 "CPM.y"
    {
 printf("OUT_STMT -> OUT '(' SENTENCE ')' ';' \n"); 
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* codeHeadStr = (char*)malloc(sizeof(char) * 100);
 char* label = getLabel();
 codeBodyStr[0]='\0';
 codeHeadStr[0]='\0';
 
 sprintf(codeHeadStr,"%s: .asciiz %s\n", label, (yyvsp[(3) - (5)].sval));
 sprintf(codeBodyStr, "la $a0,%s\nli $v0,4\nsyscall\n", label);
 
 (yyval.code).head = strdup(codeHeadStr);
 (yyval.code).body = strdup(codeBodyStr);
 free(codeHeadStr);
 free(codeBodyStr);
}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 444 "CPM.y"
    {outputError("expected '('"); isError = 0;}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 446 "CPM.y"
    {
 (yyval.code).body = strdup("");
 (yyval.code).head=strdup("");
}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 451 "CPM.y"
    {outputError("expected ')'");isError = 0;}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 453 "CPM.y"
    {
 (yyval.code).body = strdup("");
 (yyval.code).head=strdup("");
}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 458 "CPM.y"
    {outputError("expected ';'");isError = 0;}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 460 "CPM.y"
    {
 (yyval.code).body = strdup("");
 (yyval.code).head=strdup("");
}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 468 "CPM.y"
    {
 printf("READ_STMT -> READ '(' ID ')' ';' \n");
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);	
 codeBodyStr[0]='\0';
 
 symbol* sym = findInSymbolT((yyvsp[(3) - (5)].sval));
 
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
 (yyval.code).body = strdup(codeBodyStr);
}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 515 "CPM.y"
    {
 printf("ASSIGNMENT_STMT -> ID ASSIGNOP EXPRESSION ';' \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 codeBodyStr[0]='\0';
 
 char* reg;
 symbol* sym = findInSymbolT((yyvsp[(1) - (4)].sval));
 
 if (sym != NULL)
 {
  if(sym->isconst == 0)
  { 
   if(strcmp((yyvsp[(3) - (4)].dec).type, "int") == 0 && strcmp((yyvsp[(3) - (4)].dec).type, sym->type) == 0)
   {
    sprintf(codeBodyStr, "sw %s, %s\n", (yyvsp[(3) - (4)].dec).reg, (yyvsp[(1) - (4)].sval));
    freeTreg((yyvsp[(3) - (4)].dec).reg);
   }	
   else if(strcmp((yyvsp[(3) - (4)].dec).type, "float") == 0 && strcmp((yyvsp[(3) - (4)].dec).type, sym->type) == 0)
   {
    sprintf(codeBodyStr, "s.s %s, %s\n", (yyvsp[(3) - (4)].dec).reg, (yyvsp[(1) - (4)].sval));
    freeFreg((yyvsp[(3) - (4)].dec).reg);
   }
   else
   {
    if(strcmp((yyvsp[(3) - (4)].dec).type, "int") == 0 && strcmp("float", sym->type) == 0)
    {
     reg = getFreg();
     sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\ns.s %s, %s\n", (yyvsp[(3) - (4)].dec).reg, reg, reg, reg, reg, (yyvsp[(1) - (4)].sval));
     freeTreg((yyvsp[(3) - (4)].dec).reg);
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
 
 (yyval.code).head = strdup((yyvsp[(3) - (4)].dec).codeHead);
 (yyval.code).body = StrCat((yyvsp[(3) - (4)].dec).codeBody,codeBodyStr);
 free(codeBodyStr);
}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 577 "CPM.y"
    {
 printf("CONTROL_STMT -> IF '('BOOLEXPR')' STMT ELSE STMT \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * (100 + strlen((yyvsp[(5) - (7)].code).body)));
 char* label = getLabel();
 char* str;
 codeBodyStr[0]='\0';
 
 sprintf(codeBodyStr, "beq %s, $0,Else%s\n%s\nj\n%s\nEnd%s:\n", (yyvsp[(3) - (7)].dec).reg, label, label, (yyvsp[(5) - (7)].code).body, label);	
 str = StrCat(str,(yyvsp[(5) - (7)].code).head);
 
 (yyval.code).head = StrCat((yyvsp[(3) - (7)].dec).codeHead,str);
 (yyval.code).body = StrCat((yyvsp[(3) - (7)].dec).codeBody,codeBodyStr);
 freeTreg((yyvsp[(3) - (7)].dec).reg);
 free(str);
 free(codeBodyStr);
}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 595 "CPM.y"
    {outputError("expected '('");isError = 0;}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 597 "CPM.y"
    {
 (yyval.code).body=strdup("");
 (yyval.code).head=strdup("");
}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 602 "CPM.y"
    {outputError("Expected to recieve a boolean expression");isError = 0;}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 604 "CPM.y"
    {
 (yyval.code).body=strdup("");
 (yyval.code).head=strdup("");
}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 609 "CPM.y"
    {outputError("expected ')'");isError = 0;}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 611 "CPM.y"
    {
 (yyval.code).body=strdup("");
 (yyval.code).head=strdup("");
}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 618 "CPM.y"
    {
 printf("CONTROL_STMT -> WHILE '(' BOOLEXPR ')' STMT_BLOCK \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * (100 + strlen((yyvsp[(5) - (5)].code).body)));
 char* label = getLabel();
 char* str = (char*)malloc(sizeof(char) * (50 + strlen((yyvsp[(3) - (5)].dec).codeBody)));
 codeBodyStr[0]='\0';
 str[0]='\0';
 
 sprintf(codeBodyStr, "beq %s, $0, End%s\n%s\nj Loop%s\nEnd%s:\n", (yyvsp[(3) - (5)].dec).reg, label, (yyvsp[(5) - (5)].code).body, label, label);
 sprintf(str,"Loop%s:\n",label);
 strcat(str, (yyvsp[(3) - (5)].dec).codeBody);
 
 (yyval.code).head = StrCat((yyvsp[(3) - (5)].dec).codeHead, (yyvsp[(5) - (5)].code).head);
 (yyval.code).body = StrCat(str,codeBodyStr);
 freeTreg((yyvsp[(3) - (5)].dec).reg);
 free(str);
 free(codeBodyStr);
}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 638 "CPM.y"
    {outputError("expected '('");isError = 0;}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 640 "CPM.y"
    {
 (yyval.code).body=strdup("");
 (yyval.code).head=strdup("");	
}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 645 "CPM.y"
    {outputError("Expected to recieve a boolean expression");isError = 0;}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 647 "CPM.y"
    {
 (yyval.code).body=strdup("");
 (yyval.code).head=strdup("");
}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 652 "CPM.y"
    {outputError("expected ')'");isError = 0;}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 654 "CPM.y"
    {
 (yyval.code).body=strdup("");
 (yyval.code).head=strdup("");
}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 660 "CPM.y"
    {
 printf("CONTROL_STMT -> FOREACH ID ';' ASSIGNOP ';' NUM  ':' NUM  WITH STEP STMT \n");

}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 665 "CPM.y"
    {
 printf("CONTROL_STMT -> FOREACH ID ';' ASSIGNOP ';' NUM  ':' ID  WITH STEP STMT \n");

}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 672 "CPM.y"
    {
 printf("CONTROL_STMT -> DO STMT_BLOCK TILL '(' BOOLEXPR ')' \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * (100 + strlen((yyvsp[(2) - (6)].code).body)));
 char* label = getLabel();
 char* str = (char*)malloc(sizeof(char) * (50 + strlen((yyvsp[(5) - (6)].dec).codeBody)));
 codeBodyStr[0]='\0';
 str[0]='\0';
 
 sprintf(codeBodyStr, "beq %s, $0, End%s\n%s\nj Loop%s\nEnd%s:\n", (yyvsp[(5) - (6)].dec).reg, label, (yyvsp[(2) - (6)].code).body, label, label);
 sprintf(str,"Loop%s:\n",label);
 strcat(str, (yyvsp[(5) - (6)].dec).codeBody);
 
 (yyval.code).head = StrCat((yyvsp[(5) - (6)].dec).codeHead, (yyvsp[(2) - (6)].code).head);
 (yyval.code).body = StrCat(str,codeBodyStr);
 freeTreg((yyvsp[(5) - (6)].dec).reg);
 free(str);
 free(codeBodyStr);
}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 694 "CPM.y"
    {
 printf("CONTROL_STMT -> switch \n");
 (yyval.code).head = strdup((yyvsp[(1) - (1)].dec).codeHead);
 (yyval.code).body = strdup((yyvsp[(1) - (1)].dec).codeBody);
}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 703 "CPM.y"
    {
 printf("STMT_BLOCK -> '{' STMTLIST '}' \n");
 (yyval.code).head = strdup((yyvsp[(2) - (3)].code).head);
 (yyval.code).body = strdup((yyvsp[(2) - (3)].code).body);
}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 712 "CPM.y"
    {
 printf("switch -> SWITCH '(' CHOICE ')' '{' CASES '}' \n");
 (yyval.dec).codeBody = StrCat((yyvsp[(3) - (7)].dec).codeBody, (yyvsp[(6) - (7)].dec).codeBody);
 (yyval.dec).codeHead = StrCat((yyvsp[(3) - (7)].dec).codeHead, (yyvsp[(6) - (7)].dec).codeHead);
}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 721 "CPM.y"
    {
 printf("CHOICE -> ID \n");
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* reg;
 symbol* sym = findInSymbolT((yyvsp[(1) - (1)].sval));
 codeBodyStr[0]='\0';
 
 if(strcmp(sym->type, "int") == 0)
 {
  sprintf(codeBodyStr, "lw $s1,%s\n", (yyvsp[(1) - (1)].sval));
 }
 else
 {
  reg = getFreg();
  sprintf(codeBodyStr, "l.s %s,%s\n", reg, (yyvsp[(1) - (1)].sval));
 }
 
 (yyval.dec).codeHead = strdup("");
 (yyval.dec).codeBody = strdup(codeBodyStr);
 free(codeBodyStr);
}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 745 "CPM.y"
    {
 printf("CHOICE -> NUM \n");
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* codeHeadStr = (char*)malloc(sizeof(char) * 100);
 char* reg;
 codeBodyStr[0]='\0';
 codeHeadStr[0]='\0';
 
 if(strcmp((yyvsp[(1) - (1)].number).type, "int") == 0)
 {
  sprintf(codeBodyStr, "li $s1,%d\n", (yyvsp[(1) - (1)].number).val);
 }
 else
 {
  reg = getFreg();
  char* label = getLabel();
  
  sprintf(codeHeadStr,"%s: .float %f\n", label, (yyvsp[(1) - (1)].number).val);
  sprintf(codeBodyStr, "l.s %s,%s\n", reg, label);
 }
 
 (yyval.dec).codeHead = strdup(codeHeadStr);
 (yyval.dec).codeBody = strdup(codeBodyStr);
 free(codeBodyStr);
 free(codeHeadStr);
}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 775 "CPM.y"
    {
 printf("CASES -> CASE NUM ':' STMTLIST BREAK ';' CASES \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * (100 + strlen((yyvsp[(4) - (7)].code).body)));
 codeBodyStr[0]='\0';
 
 char* label = getLabel();
 char* reg=  getTreg();
 
 sprintf(codeBodyStr, "li %s, %d\nbne %s, $s1 ,next%s\n%s\nj end%s\nnext%s:\n", reg, (yyvsp[(2) - (7)].number).val.ival, reg, label, (yyvsp[(4) - (7)].code).body, (yyvsp[(7) - (7)].dec).label,label);	
 (yyval.dec).label = (yyvsp[(7) - (7)].dec).label;
 
 (yyval.dec).codeHead = StrCat((yyvsp[(4) - (7)].code).head, (yyvsp[(7) - (7)].dec).codeHead);
 (yyval.dec).codeBody = StrCat(codeBodyStr, (yyvsp[(7) - (7)].dec).codeBody);
 freeTreg(reg);
 free(codeBodyStr);
}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 795 "CPM.y"
    {
 printf("CASES -> DEFAULT ':' STMTLIST \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * (100 + strlen((yyvsp[(3) - (3)].code).body)));
 codeBodyStr[0]='\0';
 
 char* label = getLabel();
 sprintf(codeBodyStr, "default%s:\n%s\nend%s:", label, (yyvsp[(3) - (3)].code).body, label);
 
 (yyval.dec).label = strdup(label);
 (yyval.dec).codeHead = strdup((yyvsp[(3) - (3)].code).head);
 (yyval.dec).codeBody = strdup(codeBodyStr);
 free(codeBodyStr);
}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 813 "CPM.y"
    {
 printf("STEP -> ID ASSIGNOP ID ADDOP NUM \n");
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 codeBodyStr[0]='\0';
 
 symbol* sym1 = findInSymbolT((yyvsp[(1) - (5)].sval));
 symbol* sym2 = findInSymbolT((yyvsp[(3) - (5)].sval));
 
 if(strcmp(sym1->type, "int") == 0 && strcmp(sym2->type, "int") == 0 && strcmp((yyvsp[(5) - (5)].number).type, "int") == 0)
 {
  char* reg = getTreg();
  if((yyvsp[(4) - (5)].op)==PLUS)
  {
	  sprintf(codeBodyStr, "lw, %s, %s\naddi %s, %s ,%d\nsw %s, %s\n", reg, (yyvsp[(3) - (5)].sval), reg, reg, (yyvsp[(5) - (5)].number).val, reg, (yyvsp[(1) - (5)].sval));
  }
  else
  {
	  sprintf(codeBodyStr, "lw, %s, %s\nsubi %s, %s ,%d\nsw %s, %s\n", reg, (yyvsp[(3) - (5)].sval), reg, reg, (yyvsp[(5) - (5)].number).val, reg, (yyvsp[(1) - (5)].sval));
  }
    
  freeTreg(reg);
 }
 
 if(strcmp(sym1->type,"float") == 0 && strcmp(sym2->type,"float") == 0 && strcmp((yyvsp[(5) - (5)].number).type,"float") == 0)
 {
  char* reg = getFreg();
  if((yyvsp[(4) - (5)].op)==PLUS)
  {
	  sprintf(codeBodyStr, "l.s, %s, %s\nadd.s %s, %s ,%d\ns.s %s, %s\n", reg, (yyvsp[(3) - (5)].sval), reg, reg, (yyvsp[(5) - (5)].number).val, reg, (yyvsp[(1) - (5)].sval));
  }
  else
  {
	  sprintf(codeBodyStr, "l.s, %s, %s\nsub.s %s, %s ,%d\ns.s %s, %s\n", reg, (yyvsp[(3) - (5)].sval), reg, reg, (yyvsp[(5) - (5)].number).val, reg, (yyvsp[(1) - (5)].sval));
  }
    
  freeFreg(reg);																	 
 }
 
 (yyval.code).head = strdup("");
 (yyval.code).body = strdup(codeBodyStr);
 free(codeBodyStr);
}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 858 "CPM.y"
    {
 printf("STEP -> ID ASSIGNOP ID MULOP NUM \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 codeBodyStr[0]='\0';
 
 symbol* sym1 = findInSymbolT((yyvsp[(1) - (5)].sval));
 symbol* sym2 = findInSymbolT((yyvsp[(3) - (5)].sval));
 
 if(strcmp(sym1->type, "int") == 0 && strcmp(sym2->type, "int") == 0 && strcmp((yyvsp[(5) - (5)].number).type, "int") == 0)
 {
  char* reg = getTreg();
  if((yyvsp[(4) - (5)].op)==MUL)
  {
	  sprintf(codeBodyStr, "la ,%s, %s\nmul %s, %s ,%d\nsw %s, %s\n", reg, (yyvsp[(3) - (5)].sval), reg, reg, (yyvsp[(5) - (5)].number).val, reg, (yyvsp[(1) - (5)].sval));
  }
  else
  {
	  sprintf(codeBodyStr, "la ,%s, %s\ndiv %s, %s ,%d\nsw %s, %s\n", reg, (yyvsp[(3) - (5)].sval), reg, reg, (yyvsp[(5) - (5)].number).val, reg, (yyvsp[(1) - (5)].sval));
  }
    
  freeTreg(reg);
 }
 
 if(strcmp(sym1->type,"float") == 0 && strcmp(sym2->type,"float") == 0 && strcmp((yyvsp[(5) - (5)].number).type,"float") == 0)
 {
  char* reg = getFreg();
  if((yyvsp[(4) - (5)].op)==MUL)
  {
	  sprintf(codeBodyStr, "l.s, %s, %s\nmul.s %s, %s ,%d\ns.s %s, %s\n", reg, (yyvsp[(3) - (5)].sval), reg, reg, (yyvsp[(5) - (5)].number).val, reg, (yyvsp[(1) - (5)].sval));
  }
  else
  {
	  sprintf(codeBodyStr, "l.s, %s, %s\ndiv.s %s, %s ,%d\ns.s %s, %s\n", reg, (yyvsp[(3) - (5)].sval), reg, reg, (yyvsp[(5) - (5)].number).val, reg, (yyvsp[(1) - (5)].sval));
  }
    
  freeFreg(reg);																	 
 }
 
 (yyval.code).head = strdup("");
 (yyval.code).body = strdup(codeBodyStr);
 free(codeBodyStr);
}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 905 "CPM.y"
    {
 printf("BOOLEXPR -> BOOLEXPR OROP BOOLTERM  \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* tmp;
 codeBodyStr[0]='\0';
 
 char* reg = getTreg();
 char* label = getLabel();
 sprintf(codeBodyStr, "bne %s, %s, else%s\nadd %s, $0, %s\nj end%s\nelse%s: addi %s, $0, 1\nend%s", (yyvsp[(1) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg, label, reg, (yyvsp[(1) - (3)].dec).reg, label,label, reg, label);
 
 (yyval.dec).reg = strdup(reg);
 tmp = StrCat((yyvsp[(1) - (3)].dec).codeBody, (yyvsp[(3) - (3)].dec).codeBody);
 
 (yyval.dec).codeBody= StrCat(tmp,codeBodyStr);
 (yyval.dec).codeHead= StrCat((yyvsp[(1) - (3)].dec).codeHead, (yyvsp[(3) - (3)].dec).codeHead);
 freeTreg((yyvsp[(1) - (3)].dec).reg);
 freeTreg((yyvsp[(3) - (3)].dec).reg);
 free(tmp);
 free(codeBodyStr);
}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 929 "CPM.y"
    {
 printf("BOOLEXPR -> BOOLTERM \n");
 (yyval.dec).reg = strdup((yyvsp[(1) - (1)].dec).reg);
 (yyval.dec).codeBody= strdup((yyvsp[(1) - (1)].dec).codeBody);
 (yyval.dec).codeHead= strdup((yyvsp[(1) - (1)].dec).codeHead);
}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 939 "CPM.y"
    {
 printf("BOOLTERM -> BOOLTERM ANDOP BOOLFACTOR \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* tmp;
 codeBodyStr[0]='\0';
 
 char* reg = getTreg();
 sprintf(codeBodyStr, "mul %s, %s, %s\n", reg, (yyvsp[(1) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg);
 
 (yyval.dec).reg = strdup(reg);
 tmp = StrCat((yyvsp[(1) - (3)].dec).codeBody, (yyvsp[(3) - (3)].dec).codeBody);
 
 (yyval.dec).codeBody= StrCat(tmp,codeBodyStr);
 (yyval.dec).codeHead= StrCat((yyvsp[(1) - (3)].dec).codeHead, (yyvsp[(3) - (3)].dec).codeHead);
 freeTreg((yyvsp[(1) - (3)].dec).reg);
 freeTreg((yyvsp[(3) - (3)].dec).reg);
 free(tmp);
 free(codeBodyStr);
}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 962 "CPM.y"
    {
 printf("BOOLTERM -> BOOLFACTOR \n");
 (yyval.dec).reg = strdup((yyvsp[(1) - (1)].dec).reg);
 (yyval.dec).codeBody= strdup((yyvsp[(1) - (1)].dec).codeBody);
 (yyval.dec).codeHead= strdup((yyvsp[(1) - (1)].dec).codeHead);
}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 972 "CPM.y"
    {
 printf("BOOLFACTOR -> '!' '(' BOOLFACTOR ')' \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* reg = getTreg();
 codeBodyStr[0]='\0';
 
 sprintf(codeBodyStr, "li %s ,1\nsub %s, %s, %s\n", reg, (yyvsp[(3) - (4)].dec).reg, reg, (yyvsp[(3) - (4)].dec).reg);
 (yyval.dec).reg= (yyvsp[(3) - (4)].dec).reg;
 
 (yyval.dec).codeBody= StrCat((yyvsp[(3) - (4)].dec).codeBody,codeBodyStr);
 (yyval.dec).codeHead= (yyvsp[(3) - (4)].dec).codeHead;
 freeTreg(reg);
 free(codeBodyStr);
}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 990 "CPM.y"
    {
 printf("BOOLFACTOR -> EXPRESSION  RELOP  EXPRESSION \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 codeBodyStr[0]='\0';
 
 char* tmpBody =(char*)malloc(sizeof(char) * 100);
 char* tmpHead =(char*)malloc(sizeof(char) * 100);
 tmpBody[0]='\0';
 tmpHead[0]='\0';
 
 char* reg = getTreg();
 
 if(strcmp((yyvsp[(1) - (3)].dec).type, "int") == 0 && strcmp((yyvsp[(3) - (3)].dec).type, "int") == 0)
 {
  if((yyvsp[(2) - (3)].op)==EQ)
  {
	  sprintf(codeBodyStr, "seq %s, %s, %s\n", reg, (yyvsp[(1) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg);
  }
  if((yyvsp[(2) - (3)].op)==NEQ)
  {
	  sprintf(codeBodyStr, "sne %s, %s, %s\n", reg, (yyvsp[(1) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg);
  }
  if((yyvsp[(2) - (3)].op)==LT)
  {
	  sprintf(codeBodyStr, "slt %s, %s, %s\n", reg, (yyvsp[(1) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg);
  }
  if((yyvsp[(2) - (3)].op)==GT)
  {
	  sprintf(codeBodyStr, "sgt %s, %s, %s\n", reg, (yyvsp[(1) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg);
  }
  if((yyvsp[(2) - (3)].op)==LTEQ)
  {
	  sprintf(codeBodyStr, "sle %s, %s, %s\n", reg, (yyvsp[(1) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg);
  }
  if((yyvsp[(2) - (3)].op)==GTEQ)
  {
	  sprintf(codeBodyStr, "sge %s, %s, %s\n", reg, (yyvsp[(1) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg);
  }
  
  freeTreg((yyvsp[(1) - (3)].dec).reg);
  freeTreg((yyvsp[(3) - (3)].dec).reg);			
 }
 
 if(strcmp((yyvsp[(1) - (3)].dec).type,"float") == 0 && strcmp((yyvsp[(3) - (3)].dec).type,"float") == 0)
 {
  char* label = getLabel();
  if((yyvsp[(2) - (3)].op)==EQ)
  {
	  sprintf(codeBodyStr, "c.eq.s %s, %s\nbc1f else%s\naddi %s, $0,1\nj end%s\nelse%s: move %s, $0\nend%s:\n", (yyvsp[(1) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg, label, reg, label,label, reg, label);
  }
  if((yyvsp[(2) - (3)].op)==NEQ)
  {
	  sprintf(codeBodyStr, "c.eq.s %s, %s\nbc1t else%s\naddi %s, $0,1\nj end%s\nelse%s: move %s, $0\nend%s:\n", (yyvsp[(1) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg, label, reg, label,label, reg, label);
  }
  if((yyvsp[(2) - (3)].op)==LT)
  {
	  sprintf(codeBodyStr, "c.lt.s %s, %s\nbc1t else%s\naddi %s, $0,1\nj end%s\nelse%s: move %s, $0\nend%s:\n", (yyvsp[(3) - (3)].dec).reg, (yyvsp[(1) - (3)].dec).reg, label, reg, label,label, reg, label);
  }
  if((yyvsp[(2) - (3)].op)==GT)
  {
	  sprintf(codeBodyStr, "c.lt.s %s, %s\nbc1t else%s\naddi %s, $0,1\nj end%s\nelse%s: move %s, $0\nend%s:\n", (yyvsp[(1) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg, label, reg, label,label, reg, label);
  }
  if((yyvsp[(2) - (3)].op)==LTEQ)
  {
	  sprintf(codeBodyStr, "c.le.s %s, %s\nbc1t else%s\naddi %s, $0,1\nj end%s\nelse%s: move %s, $0\nend%s:\n", (yyvsp[(3) - (3)].dec).reg, (yyvsp[(1) - (3)].dec).reg, label, reg, label,label, reg, label);
  }
  if((yyvsp[(2) - (3)].op)==GTEQ)
  {
	  sprintf(codeBodyStr, "c.le.s %s, %s\nbc1t else%s\naddi %s, $0,1\nj end%s\nelse%s: move %s, $0\nend%s:\n", (yyvsp[(1) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg, label, reg, label,label, reg, label);
  }
  
  freeFreg((yyvsp[(1) - (3)].dec).reg);
  freeFreg((yyvsp[(3) - (3)].dec).reg);
 }
 
 (yyval.dec).reg = strdup(reg);
 strcat(tmpBody, (yyvsp[(1) - (3)].dec).codeBody);
 strcat(tmpBody, (yyvsp[(3) - (3)].dec).codeBody);
 strcat(tmpBody,codeBodyStr);
 strcat(tmpHead, (yyvsp[(1) - (3)].dec).codeHead);
 strcat(tmpHead, (yyvsp[(3) - (3)].dec).codeHead);
 
 (yyval.dec).codeBody = strdup(tmpBody);
 (yyval.dec).codeHead = strdup(tmpHead);
 free(tmpBody);
 free(tmpHead);
 free(codeBodyStr);
}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 1083 "CPM.y"
    {
 printf("EXPRESSION -> EXPRESSION  ADDOP  TERM \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* tmp;
 codeBodyStr[0]='\0';
 
 if(strcmp((yyvsp[(1) - (3)].dec).type, "int") == 0 && strcmp((yyvsp[(3) - (3)].dec).type, "int") == 0)
 {
  if((yyvsp[(2) - (3)].op) == PLUS)
  {
    sprintf(codeBodyStr, "add %s, %s ,%s\n", (yyvsp[(3) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg, (yyvsp[(1) - (3)].dec).reg);
  }
  else
  {
    sprintf(codeBodyStr, "sub %s, %s ,%s\n", (yyvsp[(3) - (3)].dec).reg, (yyvsp[(1) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg);
  }
  
  freeTreg((yyvsp[(1) - (3)].dec).reg);
  (yyval.dec).type = strdup("int");
  (yyval.dec).reg = strdup((yyvsp[(3) - (3)].dec).reg);
 }
 if(strcmp((yyvsp[(1) - (3)].dec).type,"float") == 0 && strcmp((yyvsp[(3) - (3)].dec).type, "int") == 0)
 {
  char* reg = getFreg();
  if((yyvsp[(2) - (3)].op) == PLUS)
  {
    sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\nadd.s %s, %s ,%s\n", (yyvsp[(3) - (3)].dec).reg, reg, reg, reg, (yyvsp[(1) - (3)].dec).reg, (yyvsp[(1) - (3)].dec).reg, reg);
  }
  else
  {
    sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\nsub.s %s, %s ,%s\n", (yyvsp[(3) - (3)].dec).reg, reg, reg, reg, (yyvsp[(1) - (3)].dec).reg, (yyvsp[(1) - (3)].dec).reg, reg);
  }
  
  freeFreg(reg);
  freeTreg((yyvsp[(3) - (3)].dec).reg);
  (yyval.dec).type = strdup("float");
  (yyval.dec).reg = strdup((yyvsp[(1) - (3)].dec).reg);
 }
 
 if(strcmp((yyvsp[(1) - (3)].dec).type, "int") == 0 && strcmp((yyvsp[(3) - (3)].dec).type,"float") == 0)
 {
  char* reg = getFreg();
  if((yyvsp[(2) - (3)].op) == PLUS)
  {
    sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\nadd.s %s, %s ,%s\n", (yyvsp[(1) - (3)].dec).reg, reg, reg, reg, (yyvsp[(3) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg, reg);
  }
  else
  {
    sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\nsub.s %s, %s ,%s\n", (yyvsp[(1) - (3)].dec).reg, reg, reg, reg, (yyvsp[(3) - (3)].dec).reg, reg, (yyvsp[(3) - (3)].dec).reg);
  }
  
  freeFreg(reg);
  freeTreg((yyvsp[(1) - (3)].dec).reg);
  (yyval.dec).type = strdup("float");
  (yyval.dec).reg = strdup((yyvsp[(3) - (3)].dec).reg);
 }
 
 if(strcmp((yyvsp[(1) - (3)].dec).type,"float") == 0 && strcmp((yyvsp[(3) - (3)].dec).type,"float") == 0)
 {
  if((yyvsp[(2) - (3)].op) == PLUS)
  {
    sprintf(codeBodyStr, "add.s %s, %s ,%s\n", (yyvsp[(3) - (3)].dec).reg, (yyvsp[(1) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg);
  }
  else
  {
    sprintf(codeBodyStr, "sub.s %s, %s ,%s\n", (yyvsp[(3) - (3)].dec).reg, (yyvsp[(1) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg);
  }
  
  freeFreg((yyvsp[(1) - (3)].dec).reg);
  (yyval.dec).type = strdup("float");
  (yyval.dec).reg = strdup((yyvsp[(3) - (3)].dec).reg);
 }
 
 tmp = StrCat((yyvsp[(1) - (3)].dec).codeBody, (yyvsp[(3) - (3)].dec).codeBody);

 (yyval.dec).codeBody= StrCat(tmp,codeBodyStr);
 (yyval.dec).codeHead= StrCat((yyvsp[(1) - (3)].dec).codeHead, (yyvsp[(3) - (3)].dec).codeHead);
 free(tmp);
 free(codeBodyStr);
}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 1167 "CPM.y"
    {
 printf("EXPRESSION -> TERM \n");
 (yyval.dec).reg =  strdup((yyvsp[(1) - (1)].dec).reg);
 (yyval.dec).codeBody = strdup((yyvsp[(1) - (1)].dec).codeBody);
 (yyval.dec).codeHead = strdup((yyvsp[(1) - (1)].dec).codeHead);
 (yyval.dec).type = strdup((yyvsp[(1) - (1)].dec).type);
}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 1178 "CPM.y"
    {
 printf("TERM -> TERM MULOP FACTOR \n");
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* tmp;
 codeBodyStr[0]='\0';
 
 if(strcmp((yyvsp[(1) - (3)].dec).type, "int") == 0 && strcmp((yyvsp[(3) - (3)].dec).type, "int") == 0)
 {
  if((yyvsp[(2) - (3)].op) == MUL) 
  {
    sprintf(codeBodyStr, "mul %s, %s ,%s\n", (yyvsp[(3) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg, (yyvsp[(1) - (3)].dec).reg);
  }
  else
  {
    sprintf(codeBodyStr, "div %s, %s ,%s\n", (yyvsp[(3) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg, (yyvsp[(1) - (3)].dec).reg);
  }
  
  freeTreg((yyvsp[(1) - (3)].dec).reg);
  (yyval.dec).type = strdup("int");
  (yyval.dec).reg = strdup((yyvsp[(3) - (3)].dec).reg);
 }
 if(strcmp((yyvsp[(1) - (3)].dec).type,"float") == 0 && strcmp((yyvsp[(3) - (3)].dec).type, "int") == 0)
 {
  char* reg = getFreg();
  if((yyvsp[(2) - (3)].op) == MUL) 
  {
    sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\nmul.s %s, %s ,%s\n", (yyvsp[(3) - (3)].dec).reg, reg, reg, reg, (yyvsp[(1) - (3)].dec).reg, (yyvsp[(1) - (3)].dec).reg, reg);
  }
  else
  {
    sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\ndiv.s %s, %s ,%s\n", (yyvsp[(3) - (3)].dec).reg, reg, reg, reg, (yyvsp[(1) - (3)].dec).reg, (yyvsp[(1) - (3)].dec).reg, reg);
  }
  
  freeFreg(reg);
  freeTreg((yyvsp[(3) - (3)].dec).reg);
  (yyval.dec).type = strdup("float");
  (yyval.dec).reg = strdup((yyvsp[(1) - (3)].dec).reg);
 }
 
 if(strcmp((yyvsp[(1) - (3)].dec).type, "int") == 0 && strcmp((yyvsp[(3) - (3)].dec).type,"float") == 0)
 {
  char* reg = getFreg();
  if((yyvsp[(2) - (3)].op) == MUL) 
  {
    sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\nmul.s %s, %s ,%s\n", (yyvsp[(1) - (3)].dec).reg, reg, reg, reg, (yyvsp[(3) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg, reg);
  }
  else
  {
    sprintf(codeBodyStr, "mtc1 %s, %s\ncvt.s.w %s, %s\ndiv.s %s, %s ,%s\n", (yyvsp[(1) - (3)].dec).reg, reg, reg, reg, (yyvsp[(3) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg, reg);
  }
  
  freeFreg(reg);
  freeTreg((yyvsp[(1) - (3)].dec).reg);
  (yyval.dec).type = strdup("float");
  (yyval.dec).reg = strdup((yyvsp[(3) - (3)].dec).reg);
 }
 if(strcmp((yyvsp[(1) - (3)].dec).type,"float") == 0 && strcmp((yyvsp[(3) - (3)].dec).type,"float") == 0)
 {
  if((yyvsp[(2) - (3)].op) == MUL)
  {
    sprintf(codeBodyStr, "mul.s %s, %s ,%s\n", (yyvsp[(3) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg, (yyvsp[(1) - (3)].dec).reg);
  }
  else
  {
    sprintf(codeBodyStr, "div.s %s, %s ,%s\n", (yyvsp[(3) - (3)].dec).reg, (yyvsp[(3) - (3)].dec).reg, (yyvsp[(1) - (3)].dec).reg);
  }
  
  freeFreg((yyvsp[(1) - (3)].dec).reg);
  (yyval.dec).type = strdup("float");
  (yyval.dec).reg = strdup((yyvsp[(3) - (3)].dec).reg);
 }			
 
 tmp = StrCat((yyvsp[(1) - (3)].dec).codeBody, (yyvsp[(3) - (3)].dec).codeBody);
 
 (yyval.dec).codeBody= StrCat(tmp,codeBodyStr);
 (yyval.dec).codeHead= StrCat((yyvsp[(1) - (3)].dec).codeHead, (yyvsp[(3) - (3)].dec).codeHead);
 free(tmp);
 free(codeBodyStr);
}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 1260 "CPM.y"
    {
 printf("TERM -> FACTOR \n");
 (yyval.dec).reg =  strdup((yyvsp[(1) - (1)].dec).reg);
 (yyval.dec).codeBody = strdup((yyvsp[(1) - (1)].dec).codeBody);
 (yyval.dec).codeHead = strdup((yyvsp[(1) - (1)].dec).codeHead);
 (yyval.dec).type = strdup((yyvsp[(1) - (1)].dec).type);
}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 1271 "CPM.y"
    {
 printf("FACTOR -> '(' EXPRESSION ')' \n");
 (yyval.dec).reg =  strdup((yyvsp[(2) - (3)].dec).reg);
 (yyval.dec).codeBody = strdup((yyvsp[(2) - (3)].dec).codeBody);
 (yyval.dec).codeHead = strdup((yyvsp[(2) - (3)].dec).codeHead);
 (yyval.dec).type = strdup((yyvsp[(2) - (3)].dec).type);
}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 1281 "CPM.y"
    {
 printf("FACTOR -> NUM \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* codeHeadStr = (char*)malloc(sizeof(char) * 100);
 char* reg;
 codeBodyStr[0]='\0';
 codeHeadStr[0]='\0';
 
 if(strcmp((yyvsp[(1) - (1)].number).type, "int") == 0)
 {
  reg = getTreg();
  sprintf(codeBodyStr, "addi %s, $0, %d\n", reg, (yyvsp[(1) - (1)].number).val.ival);
 }
 else
 {
  reg = getFreg();
  char* label = getLabel();
  sprintf(codeHeadStr,"%s: .float %f\n",label, (yyvsp[(1) - (1)].number).val.fval);
  sprintf(codeBodyStr, "l.s %s, %s\n", reg, label);
 }
 
 (yyval.dec).type = strdup((yyvsp[(1) - (1)].number).type);
 (yyval.dec).reg = strdup(reg);
 
 (yyval.dec).codeHead = strdup(codeHeadStr);
 (yyval.dec).codeBody = strdup(codeBodyStr);
 free(codeHeadStr);
 free(codeBodyStr);
}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 1314 "CPM.y"
    {
 printf("FACTOR -> ID \n");
 
 char* codeBodyStr = (char*)malloc(sizeof(char) * 100);
 char* reg;
 char* label = getLabel();
 codeBodyStr[0]='\0';
 
 symbol* sym = findInSymbolT((yyvsp[(1) - (1)].sval));
 
 if(sym !=NULL)
 {
  if(strcmp(sym->type, "int") == 0)
  {
   reg = getTreg();
   sprintf(codeBodyStr, "lw %s, %s\n", reg, (yyvsp[(1) - (1)].sval));
  }
  if(strcmp(sym->type,"float") == 0)
  {
   reg = getFreg();
   sprintf(codeBodyStr, "l.s %s, %s\n", reg, (yyvsp[(1) - (1)].sval));
  }
  if(strcmp(sym->type,"string") == 0)
  {
   reg= (yyvsp[(1) - (1)].sval);
  }
  
  (yyval.dec).reg = strdup(reg);
  (yyval.dec).type = strdup(sym->type);
  (yyval.dec).codeBody = strdup(codeBodyStr);
  (yyval.dec).codeHead=strdup("");
 }
}
    break;


/* Line 1792 of yacc.c  */
#line 3175 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 1349 "CPM.y"


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