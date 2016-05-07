%include
{
	#include "structs.h"
	#include <cassert>
	#include <cmath>
	#include <iostream>
	#include "ParserWrapper.h"
}

%token_prefix TK_
%default_type { Token }
%token_type { Token }
%type expr { Expr }
%name ParseGrammarGenerated
%extra_argument { ParserWrapper* parserWrapper }

%left PLUS.

output ::= expr(A).
{
	std::cout << A.value;
}

error ::= ERROR.

expr(X) ::= expr(A) PLUS expr(B).
{
	X.value = A.value + B.value;
}

expr(X) ::= NUMBER(A).
{
	X.value = A.value;
}