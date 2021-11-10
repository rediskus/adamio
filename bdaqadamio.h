
#ifndef _BDAQADAM_H_
#define _BDAQADAM_H_

#include <stdbool.h>
/* ЭТО ВСТАВИТЬ В GO файл! В начало в комментарий!
#cgo CFLAGS: -std=c99
#cgo LDFLAGS: -L. -l:libbio5630io.so
*/

// **********************************************************
// Bionic DAQ types
// **********************************************************
#ifndef _BDAQ_TYPES_DEFINED
#define _BDAQ_TYPES_DEFINED

/** Module ID */
typedef enum tagModuleId {
    /** ADAM-5017 Module ID: 0x04  */
    MODULEID_5017 = 0x04,
    /** ADAM-5018 Module ID: 0x05  */
    MODULEID_5018 = 0x05,
    /** ADAM-5013A Module ID: 0x08 */
    MODULEID_5013A = 0x08,
    /** ADAM-5013B Module ID: 0x09 */
    MODULEID_5013B = 0x09,
    /** ADAM-5017H Module ID: 0x0C  */
    MODULEID_5017H = 0x0C,
    /** ADAM-50137UH Module ID: 0x17  */
    MODULEID_5017UH = 0x17,
    /** ADAM-5018P Module ID: 0x38  */
    MODULEID_5018P = 0x38, //5017P

    /** ADAM-5024Module ID  */
    MODULEID_5024 = 0x18,

    //DIO
    /** ADAM-5050 Module ID: 0x10  */
    MODULEID_5050 = 0x10, //16DI/DO
    //DI
    /** ADAM-5051 Module ID: 0x11   */
    MODULEID_5051 = 0x11, //5051D 5051S
    /** ADAM-5052 Module ID: 0x0F  */
    MODULEID_5052 = 0x0F,
    /** ADAM-5053 Module ID: 0x53   */
    MODULEID_5053 = 0x53,
    //DIO
    /** ADAM-5055 Module ID: 0x15   */
    MODULEID_5055 = 0x15,
    //DO
    /** ADAM-5056 Module ID: 0x12  */
    MODULEID_5056 = 0x12, //5056D 5056S 5056SO
    /** ADAM-5057 Module ID: 0x57   */
    MODULEID_5057 = 0x57,
    //Relay
    /** ADAM-5060 Module ID: 0x14   */
    MODULEID_5060 = 0x14,
    /** ADAM-5068 Module ID: 0x13   */
    MODULEID_5068 = 0x13,
    /** ADAM-5069 Module ID: 0x69   */
    MODULEID_5069 = 0x69,
    //Cnt
    /** ADAM-5080 Module ID: 0x06   */
    MODULEID_5080 = 0x06,
    /** ADAM-5081 Module ID: 0x81   */
    MODULEID_5081 = 0x81,

    /** Unknown Module */
    MODULEID_UNDEFINE = 0xff,
    MODULEID_MASK = 0x1f,
} ModuleId;

/** AI Filter Type */
typedef enum tagAiIntegrationTime {
    /**60Hz filter(Default)*/
    Hz_60 = 0,
    /**50Hz filter*/
    Hz_50,
} AiIntegrationTime;

/** tagValueRange info */
typedef enum tagValueRange {
    /** Unknown when get, ignored when set */
    V_OMIT = -1,
    /** +/- 15 V  */
    V_Neg15To15 = 0,
    /** +/- 10 V  */
    V_Neg10To10,
    /** +/- 5 V */
    V_Neg5To5,
    /** +/- 2.5 V */
    V_Neg2pt5To2pt5,
    /** +/- 1.25 V */
    V_Neg1pt25To1pt25,
    /** +/- 1 V */
    V_Neg1To1,
    /** 0~15 V  */
    V_0To15,
    /** 0~10 V  */
    V_0To10,
    /** 0~5 V */
    V_0To5,
    /** 0~2.5 V */
    V_0To2pt5,
    /** 0~1.25 V */
    V_0To1pt25,
    /** 0~1 V */
    V_0To1,
    /** +/- 625mV */
    mV_Neg625To625,
    /** +/- 500 mV */
    mV_Neg500To500,
    /** +/- 312.5 mV */
    mV_Neg312pt5To312pt5,
    /** +/- 200 mV */
    mV_Neg200To200,
    /** +/- 150 mV */
    mV_Neg150To150,
    /** +/- 100 mV */
    mV_Neg100To100,
    /** +/- 50 mV */
    mV_Neg50To50,
    /** +/- 30 mV */
    mV_Neg30To30,
    /** +/- 20 mV */
    mV_Neg20To20,
    /** +/- 15 mV  */
    mV_Neg15To15,
    /** +/- 10 mV */
    mV_Neg10To10,
    /** +/- 5 mV */
    mV_Neg5To5,
    /** 0 ~ 625 mV */
    mV_0To625,
    /** 0 ~ 500 mV */
    mV_0To500,
    /** 0 ~ 150 mV */
    mV_0To150,
    /** 0 ~ 100 mV */
    mV_0To100,
    /** 0 ~ 50 mV */
    mV_0To50,
    /** 0 ~ 20 mV */
    mV_0To20,
    /** 0 ~ 15 mV */
    mV_0To15,
    /** 0 ~ 10 mV */
    mV_0To10,

    /** +/- 20mA */
    mA_Neg20To20,
    /** 0 ~ 20 mA */
    mA_0To20,
    /** 4 ~ 20 mA */
    mA_4To20,
    /** 0 ~ 24 mA */
    mA_0To24,

    /** +/- 2 V */
    V_Neg2To2,
    /** +/- 4 V */
    V_Neg4To4,
    /** +/- 20 V */
    V_Neg20To20,

    /** T/C J type 0~760 'C */
    Jtype_0To760C,
    /** T/C K type 0~1370 'C */
    Ktype_0To1370C,
    /** T/C T type -100~400 'C */
    Ttype_Neg100To400C,
    /** T/C E type 0~1000 'C */
    Etype_0To1000C,
    /** T/C R type 500~1750 'C */
    Rtype_500To1750C,
    /** T/C S type 500~1750 'C */
    Stype_500To1750C,
    /** T/C B type 500~1800 'C */
    Btype_500To1800C,

    /** Pt392 -50~150 'C  */
    Pt392_Neg50To150,
    /** Pt385 -200~200 'C */
    Pt385_Neg200To200,
    /** Pt385 0~400 'C */
    Pt385_0To400,
    /** Pt385 -50~150 'C */
    Pt385_Neg50To150,
    /** Pt385 -100~100 'C */
    Pt385_Neg100To100,
    /** Pt385 0~100 'C  */
    Pt385_0To100,
    /** Pt385 0~200 'C */
    Pt385_0To200,
    /** Pt385 0~600 'C */
    Pt385_0To600,
    /** Pt392 -100~100 'C  */
    Pt392_Neg100To100,
    /** Pt392 0~100 'C */
    Pt392_0To100,
    /** Pt392 0~200 'C */
    Pt392_0To200,
    /** Pt392 0~600 'C */
    Pt392_0To600,
    /** Pt392 0~400 'C */
    Pt392_0To400,
    /** Pt392 -200~200 'C  */
    Pt392_Neg200To200,
    /** Pt1000 -40~160 'C  */
    Pt1000_Neg40To160,

    /** Balcon500 -30~120 'C  */
    Balcon500_Neg30To120,
    /** Ni518 -80~100 'C */
    Ni518_Neg80To100,
    /** Ni518 0~100 'C */
    Ni518_0To100,
    /** Ni508 0~100 'C */
    Ni508_0To100,
    /** Ni508 -50~200 'C */
    Ni508_Neg50To200,

    /** Thermistor 3K 0~100 'C */
    Thermistor_3K_0To100,
    /** Thermistor 10K 0~100 'C */
    Thermistor_10K_0To100,

    /** T/C J type -210~1200 'C */
    Jtype_Neg210To1200C,
    /** T/C K type -270~1372 'C */
    Ktype_Neg270To1372C,
    /** T/C T type -270~400 'C */
    Ttype_Neg270To400C,
    /** T/C E type -270~1000 'C */
    Etype_Neg270To1000C,
    /** T/C R type -50~1768 'C */
    Rtype_Neg50To1768C,
    /** T/C S type -50~1768 'C */
    Stype_Neg50To1768C,
    /** T/C B type 40~1820 'C */
    Btype_40To1820C,

    /** T/C J type -210~870 'C */
    Jtype_Neg210To870C,
    /** T/C R type 0~1768 'C */
    Rtype_0To1768C,
    /** T/C S type 0~1768 'C */
    Stype_0To1768C,
    /** T/C T type -20~135 'C */
    Ttype_Neg20To135C,

    /** 0xC000 ~ 0xF000 : user customized value range type */
    UserCustomizedVrgStart = 0xC000,
    UserCustomizedVrgEnd = 0xF000,

    /** AO external reference type */
    V_ExternalRefBipolar = 0xF001, /** External reference voltage unipolar */
    V_ExternalRefUnipolar = 0xF002, /** External reference voltage bipolar */
} ValueRange;

/** Counter Mode */
typedef enum tagSignalCountingType {
    /** counting direction is determined by two signals, one is clock, the other is direction signal */
    ContrMod_Bi_DIR = 0,
    /** counter value increases on each clock, or increases on each clock */
    ContrMod_UP_DOWN,
    /** counter value increases on each clock*/
    ContrMod_UP,
    /** counting frequency*/
    ContrMod_Freq,
    /** AB phase, 1x rate up/down counting */
    AbPhaseX1,
    /** AB phase, 2x rate up/down counting */
    AbPhaseX2,
    /** AB phase, 4x rate up/down counting */
    AbPhaseX4,
} SignalCountingType;

/** AI Data Type */
typedef enum tagAIDataUnit {
    /** Engineer Unit*/
    EngineerUnit = 0,
    /** Percent*/
    Percent = 1,
    /** Raw data*/
    TwosComplementHex = 2,
    /** Resistance unit, for ADAM-5013*/
    Ohms = 3,
    /** Unknown type*/
    Unknown = 255,
} AIDataUnit;

/** AI Calibration Type */
typedef enum AI_CALI_MODE {
    /** Zero calibration*/
    Cali_Zero = 0,
    /** Span calibration*/
    Cali_Span,
    /** Cjc calibration, for Thermocouple module*/
    Cali_Cjc,
} AiCaliMode;

typedef enum AO_CALI_MODE {
    Cali_4mA = 0,
    Cali_20mA,
    Cali_Trim,
} AoCaliMode;
/**
* Property Attribute and Id
*/
typedef enum tagPropertyAttribute {
    ReadOnly = 0,
    Writable = 1,
    Modal = 0,
    Nature = 2,
} PropertyAttribute;

#define BioFailed(c)  ((unsigned)(c) >= (unsigned)0xE0000000)

/// <summary>
/// tagErrorCode info.
/// </summary>
typedef enum tagErrorCode {
    /// <summary>
    /// The operation is completed successfully.
    /// </summary>
    Success = 0,

    ///*************************************************************************
    /// warning
    ///*************************************************************************
    /// <summary>
    /// The interrupt resource is not available.
    /// </summary>
    WarningIntrNotAvailable = 0xA0000000,

    /// <summary>
    /// The parameter is out of the range.
    /// </summary>
    WarningParamOutOfRange = 0xA0000001,

    /// <summary>
    /// The property value is out of range.
    /// </summary>
    WarningPropValueOutOfRange = 0xA0000002,

    /// <summary>
    /// The property value is not supported.
    /// </summary>
    WarningPropValueNotSpted = 0xA0000003,

    /// <summary>
    /// The property value conflicts with the current state.
    /// </summary>
    WarningPropValueConflict = 0xA0000004,

    /// <summary>
    /// The value range of all channels in a group should be same.
    /// </summary>
    WarningVrgOfGroupNotSame = 0xA0000005,

    ///***********************************************************************
    /// error
    ///***********************************************************************
    /// <summary>
    /// The handle is NULL or its type doesn't match the required operation.
    /// </summary>
    ErrorHandleNotValid = 0xE0000000,

    /// <summary>
    /// The parameter value is out of range.
    /// </summary>
    ErrorParamOutOfRange = 0xE0000001,

    /// <summary>
    /// The parameter value is not supported.
    /// </summary>
    ErrorParamNotSpted = 0xE0000002,

    /// <summary>
    /// The parameter value format is not the expected.
    /// </summary>
    ErrorParamFmtUnexpted = 0xE0000003,

    /// <summary>
    /// Not enough memory is available to complete the operation.
    /// </summary>
    ErrorMemoryNotEnough = 0xE0000004,

    /// <summary>
    /// The data buffer is null.
    /// </summary>
    ErrorBufferIsNull = 0xE0000005,

    /// <summary>
    /// The data buffer is too small for the operation.
    /// </summary>
    ErrorBufferTooSmall = 0xE0000006,

    /// <summary>
    /// The data length exceeded the limitation.
    /// </summary>
    ErrorDataLenExceedLimit = 0xE0000007,

    /// <summary>
    /// The required function is not supported.
    /// </summary>
    ErrorFuncNotSpted = 0xE0000008,

    /// <summary>
    /// The required event is not supported.
    /// </summary>
    ErrorEventNotSpted = 0xE0000009,

    /// <summary>
    /// The required property is not supported.
    /// </summary>
    ErrorPropNotSpted = 0xE000000A,

    /// <summary>
    /// The required property is read-only.
    /// </summary>
    ErrorPropReadOnly = 0xE000000B,

    /// <summary>
    /// The specified property value conflicts with the current state.
    /// </summary>
    ErrorPropValueConflict = 0xE000000C,

    /// <summary>
    /// The specified property value is out of range.
    /// </summary>
    ErrorPropValueOutOfRange = 0xE000000D,

    /// <summary>
    /// The specified property value is not supported.
    /// </summary>
    ErrorPropValueNotSpted = 0xE000000E,

    /// <summary>
    /// The handle hasn't own the privilege of the operation the user wanted.
    /// </summary>
    ErrorPrivilegeNotHeld = 0xE000000F,

    /// <summary>
    /// The required privilege is not available because someone else had own it.
    /// </summary>
    ErrorPrivilegeNotAvailable = 0xE0000010,

    /// <summary>
    /// The driver of specified device was not found.
    /// </summary>
    ErrorDriverNotFound = 0xE0000011,

    /// <summary>
    /// The driver version of the specified device mismatched.
    /// </summary>
    ErrorDriverVerMismatch = 0xE0000012,

    /// <summary>
    /// The loaded driver count exceeded the limitation.
    /// </summary>
    ErrorDriverCountExceedLimit = 0xE0000013,

    /// <summary>
    /// The device is not opened.
    /// </summary>
    ErrorDeviceNotOpened = 0xE0000014,

    /// <summary>
    /// The required device does not exist.
    /// </summary>
    ErrorDeviceNotExist = 0xE0000015,

    /// <summary>
    /// The required device is unrecognized by driver.
    /// </summary>
    ErrorDeviceUnrecognized = 0xE0000016,

    /// <summary>
    /// The configuration data of the specified device is lost or unavailable.
    /// </summary>
    ErrorConfigDataLost = 0xE0000017,

    /// <summary>
    /// The function is not initialized and can't be started.
    /// </summary>
    ErrorFuncNotInited = 0xE0000018,

    /// <summary>
    /// The function is busy.
    /// </summary>
    ErrorFuncBusy = 0xE0000019,

    /// <summary>
    /// The interrupt resource is not available.
    /// </summary>
    ErrorIntrNotAvailable = 0xE000001A,

    /// <summary>
    /// The DMA channel is not available.
    /// </summary>
    ErrorDmaNotAvailable = 0xE000001B,

    /// <summary>
    /// Time out when reading/writing the device.
    /// </summary>
    ErrorDeviceIoTimeOut = 0xE000001C,

    /// <summary>
    /// The given signature does not match with the device current one.
    /// </summary>
    ErrorSignatureNotMatch = 0xE000001D,

    /// <summary>
    /// Undefined error
    /// </summary>
    ErrorUndefined = 0xE000FFFF,
} ErrorCode;

#endif // _BDAQ_TYPES_DEFINED

unsigned int ADAMDrvOpen(signed int *hHandle);
unsigned int ADAMDrvClose(signed int *hHandle);
unsigned int SYS_GetNodeID(signed int hHandle, unsigned short *o_usNodeID);
unsigned int SYS_GetModuleID(signed int hHandle, unsigned short i_usSlot, unsigned short *moduleid);
unsigned int SYS_GetModuleName(signed int hHandle, unsigned short i_usSlot, char *o_szName);
unsigned int AI_GetChannelTotal(signed int hHandle, unsigned short i_usSlot, unsigned short *o_usCh);

//unsigned int AI_GetChannelEnabled(signed int hHandle, unsigned short i_usSlot, bool *o_bEnabled);
//unsigned int AI_SetChannelEnabled(signed int hHandle, unsigned short i_usSlot, bool *i_bEnabled);
unsigned int AI_GetChannelEnabled(signed int hHandle, unsigned short i_usSlot, unsigned char *o_bEnabled);
unsigned int AI_SetChannelEnabled(signed int hHandle, unsigned short i_usSlot, unsigned char *i_bEnabled);

unsigned int AI_GetInputRange(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char *o_byRangeCode);
unsigned int AI_SetInputRange(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char i_byRangeCode);
unsigned int AI_GetRangeIntegrationTime(signed int hHandle, unsigned short i_usSlot, unsigned short *o_iIntegrationTime);
unsigned int AI_SetRangeIntegrationTime(signed int hHandle, unsigned short i_usSlot, unsigned short i_iIntegrationTime);
unsigned int AI_GetDataFormat(signed int hHandle, unsigned short i_usSlot, unsigned short *o_iDataFormat);
unsigned int AI_SetDataFormat(signed int hHandle, unsigned short i_usSlot, unsigned short i_iDataFormat);
unsigned int AI_GetValues(signed int hHandle, unsigned short i_usSlot, void *o_sValue, double *o_fValue);
unsigned int AI_GetValue(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, void *o_sValue, double *o_fValue);
unsigned int AI_Calibration(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char i_caliType);
unsigned int AI_Calibration_CJC(signed int hHandle, unsigned short i_usSlot, unsigned short i_iChannel, unsigned char i_caliType, float l_cjcValue);
unsigned int AO_GetChannelTotal(signed int hHandle, unsigned short i_usSlot, unsigned short *o_usCh);
unsigned int AO_GetOutputRange(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char *o_byRangeCode);
unsigned int AO_SetOutputRange(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char i_byRangeCode);
unsigned int AO_GetStartup(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, double *o_fValue);
unsigned int AO_SetStartup(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, double i_fValue);
unsigned int AO_GetValues(signed int hHandle, unsigned short i_usSlot, double *o_fValue);
unsigned int AO_GetValue(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, double *o_fValue);
unsigned int AO_SetValues(signed int hHandle, unsigned short i_usSlot, double *i_fValue);
unsigned int AO_SetValue(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, double i_fValue);
unsigned int AO_Calibration_4mA(signed int hHandle, unsigned short i_usSlot, unsigned short i_iChannel);
unsigned int AO_Calibration_20mA(signed int hHandle, unsigned short i_usSlot, unsigned short i_iChannel);
unsigned int AO_Calibration_Trim(signed int hHandle, unsigned short i_usSlot, unsigned short i_iChannel, long l_gradient);
unsigned int DIO_GetChannelTotal(signed int hHandle, unsigned short i_usSlot, unsigned short *o_usCh);
unsigned int DI_GetValues(signed int hHandle, unsigned short i_usSlot, unsigned int *o_dwValue);
unsigned int DI_GetValue(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, bool *o_bValue);
unsigned int DIO_GetUniversalStatus(signed int hHandle, unsigned short i_usSlot, unsigned short *o_dwStatus);
unsigned int DI_GetInvert(signed int hHandle, unsigned short i_usSlot, unsigned int *o_InvertMode);
unsigned int DI_SetInvert(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char i_InvertMode);
unsigned int DO_SetValue(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, bool i_bValue);
unsigned int DO_SetValues(signed int hHandle, unsigned short i_usSlot, unsigned int o_dwValue);
unsigned int DO_GetValues(signed int hHandle, unsigned short i_usSlot, unsigned int *o_dwValue);
unsigned int CNT_GetValue(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned int *o_lValue);
unsigned int CNT_ClearValue(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh);
unsigned int CNT_GetRange(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char *o_byRange);
unsigned int CNT_SetRange(unsigned int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char i_byRange);
unsigned int CNT_GetFilter(signed int hHandle, unsigned short i_usSlot, unsigned int *o_lFilter);
unsigned int CNT_SetFilter(signed int hHandle, unsigned short i_usSlot, unsigned int i_lFilter);
unsigned int CNT_GetStartup(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned int *o_lStartup);
unsigned int CNT_SetStartup(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned int i_lStartup);
unsigned int CNT_GetState(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, bool *o_bCounting);
unsigned int CNT_SetState(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, bool i_bCounting);
unsigned int CNT_GetOverflow(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, bool *o_bOverflow);
unsigned int CNT_ClearOverflow(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh);
unsigned int CNT_GetAlarmFlag(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, bool *o_bAlarmFlag);
unsigned int CNT_ClearAlarmFlag(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh);
unsigned int CNT_GetAlarmType(unsigned int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char *o_byAlarmType);
unsigned int CNT_SetAlarmType(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char i_byAlarmType);
unsigned int CNT_GetAlarmEnable(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, bool *o_bAlarmEnable);
unsigned int CNT_SetAlarmEnable(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, bool i_bAlarmEnable);
unsigned int CNT_GetAlarmMap(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char *o_byAlarmMap);
unsigned int CNT_SetAlarmMap(unsigned int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char i_byAlarmMap);
unsigned int CNT_GetAlarmLimit(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned int *o_lAlarmLimit);
unsigned int CNT_SetAlarmLimit(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned int i_lAlarmLimit);
unsigned int CNT_GetDoValue(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, bool *o_bDO);
unsigned int CNT_SetDoValue(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, bool i_bDO);
unsigned int CNT_GetDoValues(signed int hHandle, unsigned short i_usSlot, unsigned char *o_byDOs);
unsigned int CNT_SetDoValues(signed int hHandle, unsigned short i_usSlot, unsigned char i_byDOs);
unsigned int CNT_GetFreqAcqTime(signed int hHandle, unsigned short i_usSlot, unsigned int *o_lFreqActTime);
unsigned int CNT_SetFreqAcqTime(signed int hHandle, unsigned short i_usSlot, unsigned int i_lFreqActTime);
unsigned int CNT_GetRemoteAlarmFlag(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char i_bType, bool *o_bAlarmFlag);
unsigned int CNT_ClearRemoteAlarmFlag(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char i_bType);
unsigned int CNT_GetRemoteAlarmEnable(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char i_bType, bool *o_bAlarmEnable);
unsigned int CNT_SetRemoteAlarmEnable(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char i_bType, bool i_bAlarmEnable);
unsigned int CNT_GetRemoteAlarmMap(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char i_bType, unsigned short *o_usrtSlot, unsigned short *o_usrtCh);
unsigned int CNT_SetRemoteAlarmMap(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char i_bType, unsigned short i_usrtSlot, unsigned short i_usrtCh);
unsigned int CNT_GetRemoteAlarmLimit(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char i_bType, unsigned int *o_lAlarmLimit);
unsigned int CNT_SetRemoteAlarmLimit(signed int hHandle, unsigned short i_usSlot, unsigned short i_usCh, unsigned char i_bType, unsigned int i_lAlarmLimit);
unsigned int CNT_GetFwVersion(signed int hHandle, unsigned short i_usSlot, unsigned char *o_lFwVer);

#endif    // _BDAQADAM_H_
