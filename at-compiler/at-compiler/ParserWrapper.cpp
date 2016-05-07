#include "stdafx.h"
#include "ParserWrapper.h"

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