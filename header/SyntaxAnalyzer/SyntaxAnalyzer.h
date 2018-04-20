/* INCLUDE GUARD */
/****************************************/
#ifndef SYNTAXANALYZER_H_
#define SYNTAXANALYZER_H_

/* INCLUDE LIBRARIES */
/****************************************/
#include <list>
#include "../LexcialAnalyzer/Tokenizer/Token.h"
#include "ParserTable/DerivationTable.h"
#include "GrammerExtractor/ProductionElement.h"
#include "GrammerExtractor/Node.h"

using namespace std;

/* CLASS DEFINITION */
/****************************************/
class SyntaxAnalyzer {

public:
	/* CONSTRUCTOR*/
	SyntaxAnalyzer(void);
	virtual ~SyntaxAnalyzer(void);

public:
	/* INTERFACE METHODS */
	static void analyze_prog(vector<Token> user_prog , DerivationTable derivation_table);

};

#endif /* SYNTAXANALYZER_H_ */