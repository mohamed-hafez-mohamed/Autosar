/**
 *
 * \file HeightMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HeightMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 8/25/2021 07:13 م
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HeightMotor.h"


/**
 *
 * Runnable HeightMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightMotor_Move
 *
 */

void HeightMotor_Move (StepMotorStepImpType Step)
{
	Std_ReturnType status;

	/* Server Call Points */
	if(MOTOR_STEP_PLUS == step)
	{
		status = Rte_Call_rpIOSetHeight_IOSetForward();
	}
	else if(MOTOR_STEP_MINUS == step)
	{
		status = Rte_Call_rpIOSetHeight_IOSetReverse();
	}
	else
	{
		
	}
	
}

