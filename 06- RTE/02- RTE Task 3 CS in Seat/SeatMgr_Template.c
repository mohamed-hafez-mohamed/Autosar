/**
 *
 * \file SeatMgr_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatMgr
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 8/19/2021 07:57 م
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatMgr.h"


/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */

void SeatManager_SetHeight (void)
{
	Std_ReturnType       status;
	MultiStateBtnType    HeightBtnState;
	StepMotorStepImpType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	/* Logic */
	if(HeightBtnState == MULTI_STATE_BTN_MINUS)
	{
		/* Server Call Points */
	   status = Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(HeightBtnState == MULTI_STATE_BTN_PLUS)
	{
		/* Server Call Points */
		status = Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
	}

}

/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *
 */

void SeatManager_SetSlide (void)
{
	Std_ReturnType       status;
	MultiStateBtnType    SlideBtnState;
	StepMotorStepImpType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	/* Logic */
	if(SlideBtnState == MULTI_STATE_BTN_MINUS)
	{
		/* Server Call Points */
	   status = Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(SlideBtnState == MULTI_STATE_BTN_PLUS)
	{
      /* Server Call Points */
	   status = Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
	}
	
}

/**
 *
 * Runnable SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void SeatManager_SetIncline (void)
{
	Std_ReturnType       status;
	MultiStateBtnType    InclineBtnState;
	StepMotorStepImpType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	/* Logic */
	if(InclineBtnState == MULTI_STATE_BTN_MINUS)
	{
		/* Server Call Points */
	   status = Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS); 
	}
	else if(InclineBtnState == MULTI_STATE_BTN_PLUS)
	{
      /* Server Call Points */
	   status = Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);
	}

}


