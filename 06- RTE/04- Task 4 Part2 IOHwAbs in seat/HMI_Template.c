/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 8/25/2021 07:13 م
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"



/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */

void HMI_MainFunction (void)
{
	Std_ReturnType    status;

	HeightImpType     Height;
	SlideImpType      Slide;
   InclineImpType    Incline;

	MultiStateBtnType HeightBtnState;
	MultiStateBtnType SlideBtnState;
   MultiStateBtnType InclineBtnState;

   /* Data Receive Points */
	status = Rte_Read_rpSeatCtrlData_Height(&Height);
	status = Rte_Read_rpSeatCtrlData_Incline(&Incline);
	status = Rte_Read_rpSeatCtrlData_Slide(&Slide);
	/* Logic */

	/* Height Btn Logic */
	if(Timeout || NotUpdate || Height == 0)
	{
      HeightBtnState = MULTI_STATE_BTN_INIT;
	}
	else if(Height == 1)
	{
      HeightBtnState = MULTI_STATE_BTN_MINUS;
	}
	else if(Height == 2)
	{
		HeightBtnState = MULTI_STATE_BTN_PLUS;
	}

	/* Slide Btn Logic */
	if(Timeout || NotUpdate || Slide == 0)
	{
      SlideBtnState = MULTI_STATE_BTN_INIT;
	}
	else if(Slide == 1)
	{
      SlideBtnState = MULTI_STATE_BTN_MINUS;
	}
	else if(Slide == 2)
	{
		SlideBtnState = MULTI_STATE_BTN_PLUS;
	}

   /* Incline Btn Logic */
	if(Timeout || NotUpdate || Incline == 0)
	{
      InclineBtnState = MULTI_STATE_BTN_INIT;
	}
	else if(Incline == 1)
	{
      InclineBtnState = MULTI_STATE_BTN_MINUS;
	}
	else if(Incline == 2)
	{
		InclineBtnState = MULTI_STATE_BTN_PLUS;
	}
	/* Data Send Points */
	status = Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	status = Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	status = Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);
	
}
