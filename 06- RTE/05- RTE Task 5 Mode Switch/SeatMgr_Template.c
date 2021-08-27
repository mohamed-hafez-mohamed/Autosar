/**
 *
 * \file SeatMgr_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatMgr
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 8/26/2021 05:19 م
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatMgr.h"


/**
 *
 * Runnable SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoHeight_200ms
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_AUTO_ON_ENTRY
 *
 */

void SeatManager_AutoHeight (void)
{
	Std_ReturnType status;
	StepMotorStepImpType Step;
	SensorPositionType Position;

	/* Server Call Points */
	status = Rte_Call_rpHeightMotor_Move(Step);
	status = Rte_Call_rpHeightSensor_GetPosition(&Position);
	
}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_AUTO_ON_ENTRY
 *
 */

void SeatManager_AutoIncline (void)
{
	Std_ReturnType status;
	StepMotorStepImpType Step;
	SensorPositionType Position;

	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Move(Step);
	status = Rte_Call_rpInclineSensor_GetPosition(&Position);
	
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_AUTO_ON_ENTRY
 *
 */

void SeatManager_AutoSlide (void)
{
	Std_ReturnType status;
	StepMotorStepImpType Step;
	SensorPositionType Position;

	/* Server Call Points */
	status = Rte_Call_rpSlideMotor_Move(Step);
	status = Rte_Call_rpSlideSensor_GetPosition(&Position);
	
}


/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_MANUAL_ON_ENTRY
 *
 */

void SeatManager_SetHeight (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;
	StepMotorStepImpType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	
	/* Server Call Points */
	status = Rte_Call_rpHeightMotor_Move(Step);
	
}


/**
 *
 * Runnable SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_MANUAL_ON_ENTRY
 *
 */

void SeatManager_SetIncline (void)
{
	Std_ReturnType status;
	MultiStateBtnType InclineBtnState;
	StepMotorStepImpType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	
	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Move(Step);
	
}


/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_MANUAL_ON_ENTRY
 *
 */

void SeatManager_SetSlide (void)
{
	Std_ReturnType status;
	MultiStateBtnType SlideBtnState;
	StepMotorStepImpType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	
	/* Server Call Points */
	status = Rte_Call_rpSlideMotor_Move(Step);
	
}


/**
 *
 * Runnable SeatManager_Init
 *
 * Triggered By:
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_INIT_ON_ENTRY
 *
 */

void SeatManager_Init (void)
{
	Std_ReturnType status;

}

