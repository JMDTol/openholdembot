//*******************************************************************************
//
// This file is part of the OpenHoldem project
//   Download page:         http://code.google.com/p/openholdembot/
//   Forums:                http://www.maxinmontreal.com/forums/index.php
//   Licensed under GPL v3: http://www.gnu.org/licenses/gpl.html
//
//*******************************************************************************
//
// Purpose:
//
//*******************************************************************************

#ifndef INC_CPARSETREETERMINALNODENUMBER_H
#define INC_CPARSETREETERMINALNODENUMBER_H

#include "CParsetreeTerminalNode.h"

class CParseTreeTerminalNodeNumber: public CParseTreeTerminalNode {
  friend class CFormulaParser;
  friend class CParseTreeRotator;
 public:
  CParseTreeTerminalNodeNumber(int relative_line_number);
  ~CParseTreeTerminalNodeNumber();
 public:
  void MakeConstant(double value);
  void MakeAction(int action_constant);
 public:
  double Evaluate(bool log = false);
  CString EvaluateToString(bool log = false);
 public:
  // For debugging output
  CString Serialize();
 private:
  void SetUserVariable(CString name);
 protected:
  int _node_type;
  // In case of terminal node (identifier)
 private:
  // In case of terminal node (number)
  double _constant_value;
  // Line number relative to current function
  double _relative_line_number;
};

typedef CParseTreeTerminalNodeNumber *TPParseTreeTerminalNodeNumber;

#endif INC_CPARSETREETERMINALNODENUMBER_H