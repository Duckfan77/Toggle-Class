/*
 * ToggleClass.cpp
 *
 *  Created on: Jan 10, 2016
 *      Author: Colin
 */

#include "ToggleClass.h"

Toggle::Toggle(int toggle1Val, int toggle2Val)
{
	m_status = toggle1Val;
	m_toggleVal1 = toggle1Val;
	m_toggleVal2 = toggle2Val;

	m_risingEdgeMem = true;
	m_fallingEdgeMem = true;
}

//Returns true on a rising edge, else, returns false
bool Toggle::risingEdge(bool varToEdgeCheck){
	if(varToEdgeCheck){
		if(m_risingEdgeMem){
			m_risingEdgeMem = false;
			return true;
		}
	}else{
		m_risingEdgeMem = true;
		return false;
	}
	return false;
}

//Returns true on a falling edge, else, returns false
bool Toggle::fallingEdge(bool varToEdgeCheck){
	if(!varToEdgeCheck){
		if (m_fallingEdgeMem){
			m_fallingEdgeMem = false;
			return true;
		}
	}else{
		m_fallingEdgeMem = true;
		return false;
	}
	return false;
}

bool Toggle::dualEdge(bool varToEdgeCheck){
	return fallingEdge(varToEdgeCheck) || risingEdge(varToEdgeCheck);
}

//Changes the output state between the two values described in the constructor
void Toggle::toggleStatus(){
	if (m_status == m_toggleVal1){
		m_status = m_toggleVal2;
	}else{
		m_status = m_toggleVal1;
	}
}

//If an edge change is present, changes the output state and then returns the new state,
//else, returns the old state
int Toggle::toggleStatusOnEdgeChange(bool checkedVar){
	if(risingEdge(checkedVar)){
		toggleStatus();
	}
	return getStatus();
}
