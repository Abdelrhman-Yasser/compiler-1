/*
 * Tester.cpp
 * Created on: Apr 15, 2018
 * Author: Amr Hendy
 */

#include "../../header/Tester/Tester.h"

Tester::Tester() {
	// TODO Auto-generated constructor stub

}

Tester::~Tester() {
	// TODO Auto-generated destructor stub
}

void Tester::test(string file_name){
	vector<Production*> prods = GrammerParser::parse_grammer(file_name);
	string parsed_grammer_output_file = "ParsedGrammerTest.txt";
	string line = "";
	for(Production* prod : prods){
		line += "LHSNode = " + prod->get_LHS_name() + "\n";
		for(int index = 0; index < prod->get_RHS_elements().size(); index++){
			line += "elem";
			line += "  =  ";

			for(Node* node : prod->get_RHS_elements()[index]->get_nodes()){
				line += "{ " + node->get_name() + " , " + (node->get_type() == NodeType::NonTerminal ? "NT" : "T") + " }";
				line += " $$ ";
			}
			line += "\n";
		}
		line += "==========================================================================\n";
	}

	FileWriter::openNewFile(parsed_grammer_output_file);
	FileWriter::append(parsed_grammer_output_file, line);
}

