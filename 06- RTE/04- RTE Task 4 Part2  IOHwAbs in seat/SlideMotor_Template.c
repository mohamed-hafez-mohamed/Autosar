/**
 *
 * \file SlideMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SlideMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 8/25/2021 07:14 م
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SlideMotor.h"


/**
 *
 * Runnable SlideMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideMotor_Move
 *
 */

void SlideMotor_Move (StepMotorStepImpType Step)
{
	Std_ReturnType status;

	/* Server Call Points */
	if(MOTOR_STEP_PLUS == step)
	{
		status = Rte_Call_rpIOSetSlide_IOSetForward();
	}
	else if(MOTOR_STEP_MINUS == step)
	{
		status = Rte_Call_rpIOSetSlide_IOSetReverse();
	}
	else
	{
		
	}
	
}

