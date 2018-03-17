/*
 * KeyWordRule.cpp
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#include "KeyWordRule.h"

KeyWordRule::KeyWordRule() {
	// TODO Auto-generated constructor stub

}

KeyWordRule::~KeyWordRule() {
	// TODO Auto-generated destructor stub
}

// we send the string including {}
void KeyWordRule::appendkeyWords(string rule){
	string rule_str = rule.substr(1, rule.length() - 2);
	stringstream ss(rule_str);
	string keyWord;
	while(ss >> keyWord){
		keyWords.push_back(keyWord);
	}
}

Rule KeyWordRule::getKeyWordRule(){
	string rule_str;
	for(string s : keyWords){
		if(!rule_str.empty()) rule_str += "|";
		rule_str += s;
	}
	Rule rule("keyWord", rule_str);
	return rule;
}
