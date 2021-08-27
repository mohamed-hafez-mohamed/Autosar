/**
 *
 * \file IoHwAbs_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: IoHwAbs
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 8/25/2021 07:13 م
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_IoHwAbs.h"

/* For reading from Position Sensors */
#include "Adc.h"

/* For reading from Weight Sesnor */
#include "Spi.h"

/* For driving Motors (height, slide, incline) */
#include "Dio.h"

/* Shall be replaced with Inter Runnable Variable */
/* Internal variables to read Position sensors in one Adc Group */
static Adc_ValueGroupType IoHwAb_PositionSensorsReadings[ADC_GR0_NUM_CHANNELS] =
{
	/* Height */
	0,
	/* Incline */
	0,
	/* Slide */
	0
};

/**
 *
 * Runnable IoHwAbs_ECUGet_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppECUGetSensorPosition_IoGetHeight
 *
 */

void IoHwAbs_ECUGet_Height(IopositionSensorReadingType *Position)
{
	Std_ReturnType status;

	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp, IoHwAb_PositionSensorsReadings);

	if (status == E_OK)
	{
		/* IoPositionSensorReadingType has to be adjusted in arxml file */
		/* as per Adc resolution "Adc_ValueGroupType can be uint8 or uint16" */
		*position = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[0];
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}
}

/**
 *
 * Runnable IoHwAbs_ECUGet_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppECUGetSensorPosition_IoGetIncline
 *
 */

void IoHwAbs_ECUGet_Incline(IopositionSensorReadingType *Position)
{
	Std_ReturnType status;

	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp, IoHwAb_PositionSensorsReadings);

	if (status == E_OK)
	{
		/* IoPositionSensorReadingType has to be adjusted in arxml file */
		/* as per Adc resolution "Adc_ValueGroupType can be uint8 or uint16" */
		*position = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[1];
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}
}

/**
 *
 * Runnable IoHwAbs_ECUGet_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppECUGetSensorPosition_IoGetSlide
 *
 */

void IoHwAbs_ECUGet_Slide(IopositionSensorReadingType *Position)
{
	Std_ReturnType status;

	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp, IoHwAb_PositionSensorsReadings);

	if (status == E_OK)
	{
		/* IoPositionSensorReadingType has to be adjusted in arxml file */
		/* as per Adc resolution "Adc_ValueGroupType can be uint8 or uint16" */
		*position = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[2];
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}
}

/**
 *
 * Runnable IoHwAbs_ECUGet_Weight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppECUGetWeightPosition_IoGetWeight
 *
 */

void IoHwAbs_ECUGet_Weight(IoWeightSensorReadingType *weight)
{
	Std_ReturnType status;

	Spi_DataType spiData;

	status = Spi_ReadIB(SpiConf_SpiChannel_WeightSensor, &spiData);

	if (status == E_OK)
	{
		/* IoWeightSensorReadingType has to be adjusted in arxml file */
		/* as per Spi_DataType "can be uint8 or uint16" */
		*weight = (IoWeightSensorReadingType)spiData;
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}
}

/**
 *
 * Runnable IoHwAbs_ECUGet_SetReverse_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppECUSetMotor_IoSetHeightReverse
 *
 */

void IoHwAbs_ECUGet_SetReverse_Height(void)
{
	Std_ReturnType status;

	/* Write LOW to move reverse */
	Dio_WriteChannel(DioConfg_DioChannel_HeightMotorCh, STD_LOW);
}

/**
 *
 * Runnable IoHwAbs_ECUGet_SetReverse_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppECUSetMotor_IoSetInclineReverse
 *
 */

void IoHwAbs_ECUGet_SetReverse_Incline(void)
{
	Std_ReturnType status;
	/* Write LOW to move reverse */
	Dio_WriteChannel(DioConfg_DioChannel_InclineMotorCh, STD_LOW);
}

/**
 *
 * Runnable IoHwAbs_ECUGet_SetReverse_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppECUSetMotor_IoSetSlideReverse
 *
 */

void IoHwAbs_ECUGet_SetReverse_Slide(void)
{
	Std_ReturnType status;
	/* Write LOW to move reverse */
	Dio_WriteChannel(DioConfg_DioChannel_SlideMotorCh, STD_LOW);
}

/**
 *
 * Runnable IoHwAbs_ECUGet_Setforward_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppECUSetMotor_IoSetHeightForward
 *
 */

void IoHwAbs_ECUGet_Setforward_Height(void)
{
	Std_ReturnType status;
	/* Write HIGH to move forward */
	Dio_WriteChannel(DioConfg_DioChannel_HeightMotorCh, STD_HIGH);
}

/**
 *
 * Runnable IoHwAbs_ECUGet_Setforward_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppECUSetMotor_IoSetInclineForward
 *
 */

void IoHwAbs_ECUGet_Setforward_Incline(void)
{
	Std_ReturnType status;
	/* Write HIGH to move forward */
	Dio_WriteChannel(DioConfg_DioChannel_InclineMotorCh, STD_HIGH);
}

/**
 *
 * Runnable IoHwAbs_ECUGet_Setforward_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppECUSetMotor_IoSetSlideForward
 *
 */

void IoHwAbs_ECUGet_Setforward_Slide(void)
{
	Std_ReturnType status;
	/* Write HIGH to move forward */
	Dio_WriteChannel(DioConfg_DioChannel_SlideMotorCh, STD_HIGH);
}