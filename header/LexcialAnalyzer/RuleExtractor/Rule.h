/*
 * Rule.h
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#ifndef RULE_H_
#define RULE_H_

#include <string>
#include <vector>
#include <iostream>
#include "RuleElement.h"
#include "PostfixExpressionHandler.h"

using namespace std;

class Rule
{
public:
    Rule(string ruleName,
         string rulePattern,
         int    priority);

    virtual ~Rule();

    vector<RuleElement> toPostfix();

    string getRuleName();

    string getRulePattern();

    int getPriority();

private:
    string ruleName, rulePattern;
    int    priority;
};
#endif /* RULE_H_ */


//~ Formatted by Jindent --- http://www.jindent.com
