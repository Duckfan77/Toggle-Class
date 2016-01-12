/*
 * ToggleClass.h
 *
 *  Created on: Jan 10, 2016
 *      Author: Colin
 */

#ifndef TOGGLECLASS_H
#define TOGGLECLASS_H

class Toggle
{
private:
	int m_status;
	int m_toggleVal1;
	int m_toggleVal2;

	bool m_risingEdgeMem;
	bool m_fallingEdgeMem;
public:

	//toggle1Val is the current value passed to the function being toggled between two values,
	//while toggle2Val will be the value returned after the first time the toggle runs, switching between
	//them on successive toggles.
	Toggle(int toggle1Val, int toggle2Val);
	bool risingEdge(bool varToEdgeCheck);
	bool fallingEdge(bool varToEdgeCheck);
	bool dualEdge (bool varToEdgeCheck);
	void toggleStatus();

	//edgeMode is used to change which type of edge is detected, with 1 being rising edge,
	//-1 being falling edge, and 0 being dual edge.
	//The default value is 1, or rising edge.
	//If a nonvalid value is passed to edgeMode, no edge checking or value toggling takes place;
	int toggleStatusOnEdgeChange(bool varToEdgeCheck, int edgeMode = 1);

	int getStatus(){
		return m_status;
	}
};

#endif /* TOGGLECLASS_H */
