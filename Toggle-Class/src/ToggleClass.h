/*
 * ToggleClass.h
 *
 *  Created on: Jan 10, 2016
 *      Author: Colin
 */

#ifndef TOGGLECLASS_H
#define TOGGLECLASS_H

template <typename T>
class Toggle
{
private:
	T m_status;
	T m_toggleVal1;
	T m_toggleVal2;

	bool m_risingEdgeMem;
	bool m_fallingEdgeMem;
public:

	//toggle1Val is the current value passed to the function being toggled between two values,
	//while toggle2Val will be the value returned after the first time the toggle runs, switching between
	//them on successive toggles.
	Toggle(T toggle1Val, T toggle2Val);
	bool risingEdge(bool varToEdgeCheck);
	bool fallingEdge(bool varToEdgeCheck);
	bool dualEdge (bool varToEdgeCheck);
	void toggleStatus();

	//edgeMode is used to change which type of edge is detected, with 1 being rising edge,
	//-1 being falling edge, and 0 being dual edge.
	//The default value is 1, or rising edge.
	//If a nonvalid value is passed to edgeMode, no edge checking or value toggling takes place;
	T toggleStatusOnEdgeChange(bool varToEdgeCheck, int edgeMode = 1);

	T getStatus(){
		return m_status;
	}
};

#endif /* TOGGLECLASS_H */
