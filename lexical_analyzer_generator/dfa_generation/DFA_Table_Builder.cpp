/* IMPORT LIBRARIES */
/*********************************************/
#include "DFA_Table_Builder.h"

/* CONSTRUCTOR */
/*********************************************/
DFA_Table_Builder::DFA_Table_Builder(Machine nfa_machine)
{
    this->nfa_machine = nfa_machine;
}

DFA_Table_Builder::~DFA_Table_Builder(void)
{

}

/* INTERFACE METHODS */
/*********************************************/
void
DFA_Table_Builder::generate_dfa_table(void)
{
  vector<Composite_State> stack;

  /* get table first entry */
  Composite_State start_state;
  start_state.insert_new_state(nfa_machine.get_start());
  start_state=find_equivalent_states(start_state);
  stack.push_back(start_state);

  while(!stack.empty())
  {
    Composite_State tmp=stack.back() ; stack.pop_back();
    if(!dfa_table.row_found(tmp))
    {
      /* add new row */
      dfa_table.add_row(tmp);
      /* get transitions of this new entry */
      for (char i : alphabet){
        /* get states reachable by this state(s) when applying char i */
        /*-----------------------------------------------------> pending implementation*/
        Composite_State to_state = tmp.get_transtion(i) ;
        if(to_state!=NULL)
        {
          to_state = find_equivalent_states(level_one) ;
          stack.push_back(to_state) ;
          /*-----------------------------------------------------> pending implementation*/
          dfa_table.add_row_transition(tmp, i, to_state);
        }
        
      }
      
    }
    
  }

}


