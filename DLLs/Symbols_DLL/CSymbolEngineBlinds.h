#pragma once
//******************************************************************************
//
// This file is part of the OpenHoldem project
//    Source code:           https://github.com/OpenHoldem/openholdembot/
//    Forums:                http://www.maxinmontreal.com/forums/index.php
//    Licensed under GPL v3: http://www.gnu.org/licenses/gpl.html
//
//******************************************************************************
//
// Purpose: detecting blind posters
//
//******************************************************************************

#include "CVirtualSymbolEngine.h"
#include "CSymbolengineUserChair.h"
#include "..\Numerical_Functions_DLL\NumericalFunctions.h"

class CSymbolEngineBlinds: public CVirtualSymbolEngine
{
public:
	CSymbolEngineBlinds();
	~CSymbolEngineBlinds();
public:
	bool EvaluateSymbol(const CString name, double *result, bool log = false);
  CString SymbolsProvided();
public:
	// Mandatory reset-functions
	void InitOnStartup();
	void UpdateOnConnection();
	void UpdateOnHandreset();
	void UpdateOnNewRound();
	void UpdateOnMyTurn();
	void UpdateOnHeartbeat();
public:
	// Public accessors
	int bblindbits()       { return _bblindbits; }
  int opponentsblindbits();
	int playersblindbits() { return _playersblindbits; }
	int nplayersblind()    { return bitcount(_playersblindbits); }
	int nopponentsblind()  { return bitcount(opponentsblindbits()); }
private:
	bool BlindsAreUnknown();
	void CalculateBlinds();
private:
	int _playersblindbits;
	int _bblindbits;
};