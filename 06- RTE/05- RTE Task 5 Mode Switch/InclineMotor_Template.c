/**
 *
 * \file InclineMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: InclineMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 8/25/2021 07:13 م
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_InclineMotor.h"


/**
 *
 * Runnable InclineMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineMotor_Move
 *
 */

void InclineMotor_Move (StepMotorStepImpType Step)
{
	Std_ReturnType status;

	/* Server Call Points */
	if(MOTOR_STEP_PLUS == step)
	{
		status = Rte_Call_rpIOSetIncline_IOSetForward();
	}
	else if(MOTOR_STEP_MINUS == step)
	{
		status = Rte_Call_rpIOSetIncline_IOSetReverse();
	}
	else
	{
		
	}
}

