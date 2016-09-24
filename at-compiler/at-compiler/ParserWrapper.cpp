#include "stdafx.h"
#include "ParserWrapper.h"
#include "Logger.h"

using namespace std;

void *ParseGrammarGeneratedAlloc(void *(*mallocProc)(size_t));
void ParseGrammarGeneratedFree(void *p, void(*freeProc)(void*));
void ParseGrammarGenerated(void *yyp, int yymajor, Token yyminor, ParserWrapper* parserWrapper);

ParserWrapper::ParserWrapper()
{
	m_parserPtr = ParseGrammarGeneratedAlloc(malloc);
}

ParserWrapper::~ParserWrapper()
{
	ParseGrammarGeneratedFree(m_parserPtr, free);
}

void ParserWrapper::Parse(int tokenId, Token& token)
{
	ParseGrammarGenerated(m_parserPtr, tokenId, token, this);
}

void ParserWrapper::log(Token token)
{
	log("Got token " + token.toString());
}

void ParserWrapper::log(Expr expr)
{
	log("Got expr " + expr.toString());
}

void ParserWrapper::log(double d)
{
	log(to_string(d));
}

void ParserWrapper::log(std::string str)
{
	Logger::log(str);
}
