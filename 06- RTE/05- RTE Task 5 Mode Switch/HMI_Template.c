/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 8/26/2021 05:19 م
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"

static SeatControlBtnImpType btnValueToState(uint8 value)
{
	SeatControlBtnImpType btnState;

	if (value == 1)
	{
		btnState = MULTI_STATE_BTN_MINUS;
	}
	else if (value == 2)
	{
		btnState = MULTI_STATE_BTN_PLUS;
	}
	else
	{
		btnState = MULTI_STATE_BTN_INIT;
	}

	return btnState;
}

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
	MultiStateBtnType HeightBtnState;
	MultiStateBtnType InclineBtnState;
	MultiStateBtnType SlideBtnState;
	HeightImpType     Height;
	InclineImpType    Incline;
	SlideImpType      Slide;

   IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Height();
	status    = Rte_Read_rpSeatCtrlData_Height(&Height);
	if (status == RTE_E_OK && IsUpdated == TRUE)
	{

		HeightBtnState = btnValueToState(Height);
		(void)Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	}

	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Incline();
	status    = Rte_Read_rpSeatCtrlData_Incline(&Incline);
	if (status == RTE_E_OK && IsUpdated == TRUE)
	{
		InclineBtnState = btnValueToState(Incline);
		(void)Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	}

	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Slide();
	status    = Rte_Read_rpSeatCtrlData_Slide(&Slide)(&Slide);
	if (status == RTE_E_OK && IsUpdated == TRUE)
	{
		SlideBtnState = btnValueToState(Slide);
		(void)Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);
	}
	
}


/**
 *
 * Runnable HMI_SeatModeChanged
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatModeBtn_SeatModeBtn
 *
 */

void HMI_SeatModeChanged (void)
{
	Std_ReturnType  status;
	SeatModeBtnType SeatModeBtn;
	uint8           SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;

	/* Data Receive Points */
	status = Rte_Read_rpSeatModeBtn_SeatModeBtn(&SeatModeBtn);
	

	/*specify mode*/
			  
	if (SeatModeBtn == SEAT_MODE_BTN_MANUAL)
	{
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_MANUAL;
	}
	else if (SeatModeBtn == SEAT_MODE_BTN_AUTO)
	{
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_AUTO;
	}
	else
	{
		/* Save Init Mode */
	}
}

