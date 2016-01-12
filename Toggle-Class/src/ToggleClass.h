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
public:
	//toggle1Val is the current value passed to the function being toggled between two values,
	//while toggle2Val will be the value returned after the first time the toggle runs, switching between
	//them on successive toggles.
	Toggle(int toggle1Val, int toggle2Val);
	bool risingEdge(bool varToEdgeCheck);
	void toggleStatus();
	int toggleStatusOnEdgeChange(bool varToEdgeCheck);

	int getStatus(){
		return m_status;
	}
};

#endif /* TOGGLECLASS_H */
