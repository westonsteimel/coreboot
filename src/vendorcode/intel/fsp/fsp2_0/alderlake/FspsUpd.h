/** @file

Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.
* Neither the name of Intel Corporation nor the names of its contributors may
  be used to endorse or promote products derived from this software without
  specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
  THE POSSIBILITY OF SUCH DAMAGE.

  This file is automatically generated. Please do NOT modify !!!

**/

#ifndef __FSPSUPD_H__
#define __FSPSUPD_H__

#include <FspUpd.h>

#pragma pack(1)


///
/// Azalia Header structure
///
typedef struct {
  UINT16 VendorId;           ///< Codec Vendor ID
  UINT16 DeviceId;           ///< Codec Device ID
  UINT8  RevisionId;         ///< Revision ID of the codec. 0xFF matches any revision.
  UINT8  SdiNum;             ///< SDI number, 0xFF matches any SDI.
  UINT16 DataDwords;         ///< Number of data DWORDs pointed by the codec data buffer.
  UINT32 Reserved;           ///< Reserved for future use. Must be set to 0.
} AZALIA_HEADER;

///
/// Audio Azalia Verb Table structure
///
typedef struct {
  AZALIA_HEADER Header;      ///< AZALIA PCH header
  UINT32        *Data;       ///< Pointer to the data buffer. Its length is specified in the header
} AUDIO_AZALIA_VERB_TABLE;

///
/// Refer to the definition of PCH_INT_PIN
///
typedef enum {
  SiPchNoInt,        ///< No Interrupt Pin
  SiPchIntA,
  SiPchIntB,
  SiPchIntC,
  SiPchIntD
} SI_PCH_INT_PIN;
///
/// The PCH_DEVICE_INTERRUPT_CONFIG block describes interrupt pin, IRQ and interrupt mode for PCH device.
///
typedef struct {
  UINT8        Device;                  ///< Device number
  UINT8        Function;                ///< Device function
  UINT8        IntX;                    ///< Interrupt pin: INTA-INTD (see SI_PCH_INT_PIN)
  UINT8        Irq;                     ///< IRQ to be set for device.
} SI_PCH_DEVICE_INTERRUPT_CONFIG;

#define SI_PCH_MAX_DEVICE_INTERRUPT_CONFIG  64       ///< Number of all PCH devices


/** Fsp S Configuration
**/
typedef struct {

/** Offset 0x0040 - Reserved
**/
  UINT8                      Reserved0[16];

/** Offset 0x0050 - Graphics Configuration Ptr
  Points to VBT
**/
  UINT32                      GraphicsConfigPtr;

/** Offset 0x0054 - Enable Device 4
  Enable/disable Device 4
  $EN_DIS
**/
  UINT8                       Device4Enable;

/** Offset 0x0055 - Reserved
**/
  UINT8                       Reserved1[3];

/** Offset 0x0058 - MicrocodeRegionBase
  Memory Base of Microcode Updates
**/
  UINT32                      MicrocodeRegionBase;

/** Offset 0x005C - MicrocodeRegionSize
  Size of Microcode Updates
**/
  UINT32                      MicrocodeRegionSize;

/** Offset 0x0060 - Reserved
**/
  UINT8                       Reserved2;

/** Offset 0x0061 - Enable SATA SALP Support
  Enable/disable SATA Aggressive Link Power Management.
  $EN_DIS
**/
  UINT8                       SataSalpSupport;

/** Offset 0x0062 - Enable SATA ports
  Enable/disable SATA ports. One byte for each port, byte0 for port0, byte1 for port1,
  and so on.
**/
  UINT8                       SataPortsEnable[8];

/** Offset 0x006A - Enable SATA DEVSLP Feature
  Enable/disable SATA DEVSLP per port. 0 is disable, 1 is enable. One byte for each
  port, byte0 for port0, byte1 for port1, and so on.
**/
  UINT8                       SataPortsDevSlp[8];

/** Offset 0x0072 - Reserved
**/
  UINT8                       Reserved3[34];

/** Offset 0x0094 - Enable USB2 ports
  Enable/disable per USB2 ports. One byte for each port, byte0 for port0, byte1 for
  port1, and so on.
**/
  UINT8                       PortUsb20Enable[16];

/** Offset 0x00A4 - Enable USB3 ports
  Enable/disable per USB3 ports. One byte for each port, byte0 for port0, byte1 for
  port1, and so on.
**/
  UINT8                       PortUsb30Enable[10];

/** Offset 0x00AE - Enable xDCI controller
  Enable/disable to xDCI controller.
  $EN_DIS
**/
  UINT8                       XdciEnable;

/** Offset 0x00AF - Reserved
**/
  UINT8                       Reserved4;

/** Offset 0x00B0 - Address of PCH_DEVICE_INTERRUPT_CONFIG table.
  The address of the table of PCH_DEVICE_INTERRUPT_CONFIG.
**/
  UINT32                      DevIntConfigPtr;

/** Offset 0x00B4 - Number of DevIntConfig Entry
  Number of Device Interrupt Configuration Entry. If this is not zero, the DevIntConfigPtr
  must not be NULL.
**/
  UINT8                       NumOfDevIntConfig;

/** Offset 0x00B5 - Reserved
**/
  UINT8                       Reserved5[20];

/** Offset 0x00C9 - Enable SATA
  Enable/disable SATA controller.
  $EN_DIS
**/
  UINT8                       SataEnable;

/** Offset 0x00CA - SATA Mode
  Select SATA controller working mode.
  0:AHCI, 1:RAID
**/
  UINT8                       SataMode;

/** Offset 0x00CB - SPIn Device Mode
  Selects SPI operation mode. N represents controller index: SPI0, SPI1, ... Available
  modes: 0:SerialIoSpiDisabled, 1:SerialIoSpiPci, 2:SerialIoSpiHidden
**/
  UINT8                       SerialIoSpiMode[7];

/** Offset 0x00D2 - Reserved
**/
  UINT8                       Reserved6[35];

/** Offset 0x00F5 - SPIn Default Chip Select Mode HW/SW
  Sets Default CS Mode Hardware or Software. N represents controller index: SPI0,
  SPI1, ... Available options: 0:HW, 1:SW
**/
  UINT8                       SerialIoSpiCsMode[7];

/** Offset 0x00FC - SPIn Default Chip Select State Low/High
  Sets Default CS State Low or High. N represents controller index: SPI0, SPI1, ...
  Available options: 0:Low, 1:High
**/
  UINT8                       SerialIoSpiCsState[7];

/** Offset 0x0103 - UARTn Device Mode
  Selects Uart operation mode. N represents controller index: Uart0, Uart1, ... Available
  modes: 0:SerialIoUartDisabled, 1:SerialIoUartPci, 2:SerialIoUartHidden, 3:SerialIoUartCom,
  4:SerialIoUartSkipInit
**/
  UINT8                       SerialIoUartMode[7];

/** Offset 0x010A - Reserved
**/
  UINT8                       Reserved7[65];

/** Offset 0x014B - Enables UART hardware flow control, CTS and RTS lines
  Enables UART hardware flow control, CTS and RTS lines.
**/
  UINT8                       SerialIoUartAutoFlow[7];

/** Offset 0x0152 - Reserved
**/
  UINT8                       Reserved8[2];

/** Offset 0x0154 - SerialIoUartRtsPinMuxPolicy
  Select SerialIo Uart Rts pin muxing. Refer to GPIO_*_MUXING_SERIALIO_UARTx_RTS*
  for possible values.
**/
  UINT32                      SerialIoUartRtsPinMuxPolicy[7];

/** Offset 0x0170 - SerialIoUartCtsPinMuxPolicy
  Select SerialIo Uart Cts pin muxing. Refer to GPIO_*_MUXING_SERIALIO_UARTx_CTS*
  for possible values.
**/
  UINT32                      SerialIoUartCtsPinMuxPolicy[7];

/** Offset 0x018C - SerialIoUartRxPinMuxPolicy
  Select SerialIo Uart Rx pin muxing. Refer to GPIO_*_MUXING_SERIALIO_UARTx_RX* for
  possible values.
**/
  UINT32                      SerialIoUartRxPinMuxPolicy[7];

/** Offset 0x01A8 - SerialIoUartTxPinMuxPolicy
  Select SerialIo Uart Tx pin muxing. Refer to GPIO_*_MUXING_SERIALIO_UARTx_TX* for
  possible values.
**/
  UINT32                      SerialIoUartTxPinMuxPolicy[7];

/** Offset 0x01C4 - UART Number For Debug Purpose
  UART number for debug purpose. 0:UART0, 1:UART1, 2:UART2, 3:UART3, 4:UART4, 5:UART5,
  6:UART6. Note: If UART0 is selected as CNVi BT Core interface, it cannot be used
  for debug purpose.
   0:UART0, 1:UART1, 2:UART2, 3:UART3, 4:UART4, 5:UART5, 6:UART6
**/
  UINT8                       SerialIoDebugUartNumber;

/** Offset 0x01C5 - Reserved
**/
  UINT8                       Reserved9[7];

/** Offset 0x01CC - I2Cn Device Mode
  Selects I2c operation mode. N represents controller index: I2c0, I2c1, ... Available
  modes: 0:SerialIoI2cDisabled, 1:SerialIoI2cPci, 2:SerialIoI2cHidden
**/
  UINT8                       SerialIoI2cMode[8];

/** Offset 0x01D4 - Serial IO I2C SDA Pin Muxing
  Select SerialIo I2c Sda pin muxing. Refer to GPIO_*_MUXING_SERIALIO_I2Cx_SDA* for
  possible values.
**/
  UINT32                      PchSerialIoI2cSdaPinMux[8];

/** Offset 0x01F4 - Serial IO I2C SCL Pin Muxing
  Select SerialIo I2c Scl pin muxing. Refer to GPIO_*_MUXING_SERIALIO_I2Cx_SCL* for
  possible values.
**/
  UINT32                      PchSerialIoI2cSclPinMux[8];

/** Offset 0x0214 - Reserved
**/
  UINT8                       Reserved10[192];

/** Offset 0x02D4 - USB Per Port HS Preemphasis Bias
  USB Per Port HS Preemphasis Bias. 000b-0mV, 001b-11.25mV, 010b-16.9mV, 011b-28.15mV,
  100b-28.15mV, 101b-39.35mV, 110b-45mV, 111b-56.3mV. One byte for each port.
**/
  UINT8                       Usb2PhyPetxiset[16];

/** Offset 0x02E4 - USB Per Port HS Transmitter Bias
  USB Per Port HS Transmitter Bias. 000b-0mV, 001b-11.25mV, 010b-16.9mV, 011b-28.15mV,
  100b-28.15mV, 101b-39.35mV, 110b-45mV, 111b-56.3mV, One byte for each port.
**/
  UINT8                       Usb2PhyTxiset[16];

/** Offset 0x02F4 - USB Per Port HS Transmitter Emphasis
  USB Per Port HS Transmitter Emphasis. 00b - Emphasis OFF, 01b - De-emphasis ON,
  10b - Pre-emphasis ON, 11b - Pre-emphasis & De-emphasis ON. One byte for each port.
**/
  UINT8                       Usb2PhyPredeemp[16];

/** Offset 0x0304 - USB Per Port Half Bit Pre-emphasis
  USB Per Port Half Bit Pre-emphasis. 1b - half-bit pre-emphasis, 0b - full-bit pre-emphasis.
  One byte for each port.
**/
  UINT8                       Usb2PhyPehalfbit[16];

/** Offset 0x0314 - Enable the write to USB 3.0 TX Output -3.5dB De-Emphasis Adjustment
  Enable the write to USB 3.0 TX Output -3.5dB De-Emphasis Adjustment. Each value
  in arrary can be between 0-1. One byte for each port.
**/
  UINT8                       Usb3HsioTxDeEmphEnable[10];

/** Offset 0x031E - USB 3.0 TX Output -3.5dB De-Emphasis Adjustment Setting
  USB 3.0 TX Output -3.5dB De-Emphasis Adjustment Setting, HSIO_TX_DWORD5[21:16],
  <b>Default = 29h</b> (approximately -3.5dB De-Emphasis). One byte for each port.
**/
  UINT8                       Usb3HsioTxDeEmph[10];

/** Offset 0x0328 - Enable the write to USB 3.0 TX Output Downscale Amplitude Adjustment
  Enable the write to USB 3.0 TX Output Downscale Amplitude Adjustment, Each value
  in arrary can be between 0-1. One byte for each port.
**/
  UINT8                       Usb3HsioTxDownscaleAmpEnable[10];

/** Offset 0x0332 - USB 3.0 TX Output Downscale Amplitude Adjustment
  USB 3.0 TX Output Downscale Amplitude Adjustment, HSIO_TX_DWORD8[21:16], <b>Default
  = 00h</b>. One byte for each port.
**/
  UINT8                       Usb3HsioTxDownscaleAmp[10];

/** Offset 0x033C - Reserved
**/
  UINT8                       Reserved11[80];

/** Offset 0x038C - Enable LAN
  Enable/disable LAN controller.
  $EN_DIS
**/
  UINT8                       PchLanEnable;

/** Offset 0x038D - Reserved
**/
  UINT8                       Reserved12[11];

/** Offset 0x0398 - PCIe PTM enable/disable
  Enable/disable Precision Time Measurement for PCIE Root Ports.
**/
  UINT8                       PciePtm[28];

/** Offset 0x03B4 - Reserved
**/
  UINT8                       Reserved13[81];

/** Offset 0x0405 - Transition time in microseconds from Low Current Mode Voltage to High Current Mode Voltage
  This field has 1us resolution. When value is 0 PCH will not transition VCCIN_AUX
  to low current mode voltage.
**/
  UINT8                       PchFivrVccinAuxLowToHighCurModeVolTranTime;

/** Offset 0x0406 - Transition time in microseconds from Retention Mode Voltage to High Current Mode Voltage
  This field has 1us resolution. When value is 0 PCH will not transition VCCIN_AUX
  to retention mode voltage.
**/
  UINT8                       PchFivrVccinAuxRetToHighCurModeVolTranTime;

/** Offset 0x0407 - Reserved
**/
  UINT8                       Reserved14;

/** Offset 0x0408 - Transition time in microseconds from Off (0V) to High Current Mode Voltage
  This field has 1us resolution. When value is 0 Transition to 0V is disabled.
**/
  UINT16                      PchFivrVccinAuxOffToHighCurModeVolTranTime;

/** Offset 0x040A - Reserved
**/
  UINT8                       Reserved15[42];

/** Offset 0x0434 - CNVi Configuration
  This option allows for automatic detection of Connectivity Solution. [Auto Detection]
  assumes that CNVi will be enabled when available, [Disable] allows for disabling CNVi.
  0:Disable, 1:Auto
**/
  UINT8                       CnviMode;

/** Offset 0x0435 - Reserved
**/
  UINT8                       Reserved16;

/** Offset 0x0436 - CNVi BT Core
  Enable/Disable CNVi BT Core, Default is ENABLE. 0: DISABLE, 1: ENABLE
  $EN_DIS
**/
  UINT8                       CnviBtCore;

/** Offset 0x0437 - CNVi BT Audio Offload
  Enable/Disable BT Audio Offload, Default is DISABLE. 0: DISABLE, 1: ENABLE
  $EN_DIS
**/
  UINT8                       CnviBtAudioOffload;

/** Offset 0x0438 - Reserved
**/
  UINT8                       Reserved17[4];

/** Offset 0x043C - CNVi RF_RESET pin muxing
  Select CNVi RF_RESET# pin depending on board routing. ADP-P/M: GPP_A8 = 0x2942E408(default)
  or GPP_F4 = 0x194CE404. ADP-S: 0. Refer to GPIO_*_MUXING_CNVI_RF_RESET_* in GpioPins*.h.
**/
  UINT32                      CnviRfResetPinMux;

/** Offset 0x0440 - CNVi CLKREQ pin muxing
  Select CNVi CLKREQ pin depending on board routing. ADP-P/M: GPP_A9 = 0x3942E609(default)
  or GPP_F5 = 0x394CE605. ADP-S: 0. Refer to GPIO_*_MUXING_CNVI_CRF_XTAL_CLKREQ_*
  in GpioPins*.h.
**/
  UINT32                      CnviClkreqPinMux;

/** Offset 0x0444 - Reserved
**/
  UINT8                       Reserved18[172];

/** Offset 0x04F0 - CdClock Frequency selection
  0 (Default) Auto (Max based on reference clock frequency),  0: 192, 1: 307.2, 2:
  312 Mhz, 3: 324Mhz, 4: 326.4 Mhz, 5: 552 Mhz, 6: 556.8 Mhz, 7: 648 Mhz, 8: 652.8 Mhz
  0xFF: Auto (Max based on reference clock frequency), 0: 192, 1: 307.2, 2: 312 Mhz,
  3: 324Mhz, 4: 326.4 Mhz, 5: 552 Mhz, 6: 556.8 Mhz, 7: 648 Mhz, 8: 652.8 Mhz
**/
  UINT8                       CdClock;

/** Offset 0x04F1 - Enable/Disable PeiGraphicsPeimInit
  <b>Enable(Default):</b> FSP will initialize the framebuffer and provide it via EFI_PEI_GRAPHICS_INFO_HOB.
  Disable: FSP will NOT initialize the framebuffer.
  $EN_DIS
**/
  UINT8                       PeiGraphicsPeimInit;

/** Offset 0x04F2 - Enable D3 Hot in TCSS
  This policy will enable/disable D3 hot support in IOM
  $EN_DIS
**/
  UINT8                       D3HotEnable;

/** Offset 0x04F3 - Reserved
**/
  UINT8                       Reserved19;

/** Offset 0x04F4 - TypeC port GPIO setting
  GPIO Ping number for Type C Aux Oritation setting, use the GpioPad that is defined
  in GpioPinsXXXH.h and GpioPinsXXXLp.h as argument.(XXX is platform name, Ex: Adl
  = AlderLake)
**/
  UINT32                      IomTypeCPortPadCfg[8];

/** Offset 0x0514 - Reserved
**/
  UINT8                       Reserved20[8];

/** Offset 0x051C - Enable D3 Cold in TCSS
  This policy will enable/disable D3 cold support in IOM
  $EN_DIS
**/
  UINT8                       D3ColdEnable;

/** Offset 0x051D - Reserved
**/
  UINT8                       Reserved21[3];

/** Offset 0x0520 - Intel Graphics VBT (Video BIOS Table) Size
  Size of Internal Graphics VBT Image
**/
  UINT32                      VbtSize;

/** Offset 0x0524 - Platform LID Status for LFP Displays.
  LFP Display Lid Status (LID_STATUS enum): 0 (Default): LidClosed, 1: LidOpen.
  0: LidClosed, 1: LidOpen
**/
  UINT8                       LidStatus;

/** Offset 0x0525 - Reserved
**/
  UINT8                       Reserved22[8];

/** Offset 0x052D - Enable VMD controller
  Enable/disable to VMD controller.0: Disable; 1: Enable(Default)
  $EN_DIS
**/
  UINT8                       VmdEnable;

/** Offset 0x052E - Reserved
**/
  UINT8                       Reserved23[120];

/** Offset 0x05A6 - TCSS Aux Orientation Override Enable
  Bits 0, 2, ... 10 control override enables, bits 1, 3, ... 11 control overrides
**/
  UINT16                      TcssAuxOri;

/** Offset 0x05A8 - TCSS HSL Orientation Override Enable
  Bits 0, 2, ... 10 control override enables, bits 1, 3, ... 11 control overrides
**/
  UINT16                      TcssHslOri;

/** Offset 0x05AA - Reserved
**/
  UINT8                       Reserved24;

/** Offset 0x05AB - ITBT Root Port Enable
  ITBT Root Port Enable, 0:Disable, 1:Enable
  0:Disable, 1:Enable
**/
  UINT8                       ITbtPcieRootPortEn[4];

/** Offset 0x05AF - Reserved
**/
  UINT8                       Reserved25[3];

/** Offset 0x05B2 - ITbtConnectTopology Timeout value
  ITbtConnectTopologyTimeout value. Specified increment values in miliseconds. Range
  is 0-10000. 100 = 100 ms.
**/
  UINT16                      ITbtConnectTopologyTimeoutInMs;

/** Offset 0x05B4 - Reserved
**/
  UINT8                       Reserved26[7];

/** Offset 0x05BB - Enable/Disable PTM
  This policy will enable/disable Precision Time Measurement for TCSS PCIe Root Ports
  $EN_DIS
**/
  UINT8                       PtmEnabled[4];

/** Offset 0x05BF - Reserved
**/
  UINT8                       Reserved27[200];

/** Offset 0x0687 - Skip Multi-Processor Initialization
  When this is skipped, boot loader must initialize processors before SilicionInit
  API. </b>0: Initialize; <b>1: Skip
  $EN_DIS
**/
  UINT8                       SkipMpInit;

/** Offset 0x0688 - Reserved
**/
  UINT8                      Reserved28[8];

/** Offset 0x0690 - CpuMpPpi
  <b>Optional</b> pointer to the boot loader's implementation of EFI_PEI_MP_SERVICES_PPI.
  If not NULL, FSP will use the boot loader's implementation of multiprocessing.
  See section 5.1.4 of the FSP Integration Guide for more details.
**/
  UINT32                      CpuMpPpi;

/** Offset 0x0694 - Reserved
**/
  UINT8                       Reserved29[60];

/** Offset 0x06D0 - Enable Power Optimizer
  Enable DMI Power Optimizer on PCH side.
  $EN_DIS
**/
  UINT8                       PchPwrOptEnable;

/** Offset 0x06D1 - Reserved
**/
  UINT8                       Reserved30[33];

/** Offset 0x06F2 - Enable PCH ISH SPI Cs0 pins assigned
  Set if ISH SPI Cs0 pins are to be enabled by BIOS. 0: Disable; 1: Enable.
**/
  UINT8                       PchIshSpiCs0Enable[1];

/** Offset 0x06F3 - Reserved
**/
  UINT8                       Reserved31[2];

/** Offset 0x06F5 - Enable PCH ISH SPI pins assigned
  Set if ISH SPI native pins are to be enabled by BIOS. 0: Disable; 1: Enable.
**/
  UINT8                       PchIshSpiEnable[1];

/** Offset 0x06F6 - Enable PCH ISH UART pins assigned
  Set if ISH UART native pins are to be enabled by BIOS. 0: Disable; 1: Enable.
**/
  UINT8                       PchIshUartEnable[2];

/** Offset 0x06F8 - Enable PCH ISH I2C pins assigned
  Set if ISH I2C native pins are to be enabled by BIOS. 0: Disable; 1: Enable.
**/
  UINT8                       PchIshI2cEnable[3];

/** Offset 0x06FB - Enable PCH ISH GP pins assigned
  Set if ISH GP native pins are to be enabled by BIOS. 0: Disable; 1: Enable.
**/
  UINT8                       PchIshGpEnable[8];

/** Offset 0x0703 - Reserved
**/
  UINT8                       Reserved32[2];

/** Offset 0x0705 - Enable LOCKDOWN BIOS LOCK
  Enable the BIOS Lock feature and set EISS bit (D31:F5:RegDCh[5]) for the BIOS region
  protection.
  $EN_DIS
**/
  UINT8                       PchLockDownBiosLock;

/** Offset 0x0706 - Reserved
**/
  UINT8                       Reserved33[2];

/** Offset 0x0708 - RTC Cmos Memory Lock
  Enable RTC lower and upper 128 byte Lock bits to lock Bytes 38h-3Fh in the upper
  and and lower 128-byte bank of RTC RAM.
  $EN_DIS
**/
  UINT8                       RtcMemoryLock;

/** Offset 0x0709 - Enable PCIE RP HotPlug
  Indicate whether the root port is hot plug available.
**/
  UINT8                       PcieRpHotPlug[28];

/** Offset 0x0725 - Reserved
**/
  UINT8                       Reserved34[56];

/** Offset 0x075D - Enable PCIE RP Clk Req Detect
  Probe CLKREQ# signal before enabling CLKREQ# based power management.
**/
  UINT8                       PcieRpClkReqDetect[28];

/** Offset 0x0779 - PCIE RP Advanced Error Report
  Indicate whether the Advanced Error Reporting is enabled.
**/
  UINT8                       PcieRpAdvancedErrorReporting[28];

/** Offset 0x0795 - Reserved
**/
  UINT8                       Reserved35[196];

/** Offset 0x0859 - PCIE RP Max Payload
  Max Payload Size supported, Default 128B, see enum PCH_PCIE_MAX_PAYLOAD.
**/
  UINT8                       PcieRpMaxPayload[28];

/** Offset 0x0875 - Touch Host Controller Port 0 Assignment
  Assign THC Port 0
  0x0:ThcAssignmentNone, 0x1:ThcAssignmentThc0
**/
  UINT8                       ThcPort0Assignment;

/** Offset 0x0876 - Reserved
**/
  UINT8                       Reserved36[7];

/** Offset 0x087D - Touch Host Controller Port 1 Assignment
  Assign THC Port 1
  0x0:ThcAssignmentNone, 0x1:ThcPort1AssignmentThc0, 0x2:ThcAssignmentThc1
**/
  UINT8                       ThcPort1Assignment;

/** Offset 0x087E - Reserved
**/
  UINT8                       Reserved37[91];

/** Offset 0x08D9 - PCIE RP Aspm
  The ASPM configuration of the root port (see: PCH_PCIE_ASPM_CONTROL). Default is
  PchPcieAspmAutoConfig.
**/
  UINT8                       PcieRpAspm[28];

/** Offset 0x08F5 - PCIE RP L1 Substates
  The L1 Substates configuration of the root port (see: PCH_PCIE_L1SUBSTATES_CONTROL).
  Default is PchPcieL1SubstatesL1_1_2.
**/
  UINT8                       PcieRpL1Substates[28];

/** Offset 0x0911 - Reserved
**/
  UINT8                       Reserved38[28];

/** Offset 0x092D - PCIE RP Ltr Enable
  Latency Tolerance Reporting Mechanism.
**/
  UINT8                       PcieRpLtrEnable[28];

/** Offset 0x0949 - Reserved
**/
  UINT8                       Reserved39[104];

/** Offset 0x09B1 - PCIE Compliance Test Mode
  Compliance Test Mode shall be enabled when using Compliance Load Board.
  $EN_DIS
**/
  UINT8                       PcieComplianceTestMode;

/** Offset 0x09B2 - Reserved
**/
  UINT8                       Reserved40[27];

/** Offset 0x09CD - PCH Sata Pwr Opt Enable
  SATA Power Optimizer on PCH side.
  $EN_DIS
**/
  UINT8                       SataPwrOptEnable;

/** Offset 0x09CE - Reserved
**/
  UINT8                       Reserved41[50];

/** Offset 0x0A00 - Enable SATA Port DmVal
  DITO multiplier. Default is 15.
**/
  UINT8                       SataPortsDmVal[8];

/** Offset 0x0A08 - Enable SATA Port DmVal
  DEVSLP Idle Timeout (DITO), Default is 625.
**/
  UINT16                      SataPortsDitoVal[8];

/** Offset 0x0A18 - Reserved
**/
  UINT8                       Reserved42[62];

/** Offset 0x0A56 - USB2 Port Over Current Pin
  Describe the specific over current pin number of USB 2.0 Port N.
**/
  UINT8                       Usb2OverCurrentPin[16];

/** Offset 0x0A66 - USB3 Port Over Current Pin
  Describe the specific over current pin number of USB 3.0 Port N.
**/
  UINT8                       Usb3OverCurrentPin[10];

/** Offset 0x0A70 - Reserved
**/
  UINT8                       Reserved43[16];

/** Offset 0x0A80 - Enable 8254 Static Clock Gating
  Set 8254CGE=1 is required for SLP_S0 support. However, set 8254CGE=1 in POST time
  might fail to boot legacy OS using 8254 timer. Make sure it is disabled to support
  legacy OS using 8254 timer. Also enable this while S0ix is enabled.
  $EN_DIS
**/
  UINT8                       Enable8254ClockGating;

/** Offset 0x0A81 - Enable 8254 Static Clock Gating On S3
  This is only applicable when Enable8254ClockGating is disabled. FSP will do the
  8254 CGE programming on S3 resume when Enable8254ClockGatingOnS3 is enabled. This
  avoids the SMI requirement for the programming.
  $EN_DIS
**/
  UINT8                       Enable8254ClockGatingOnS3;

/** Offset 0x0A82 - Reserved
**/
  UINT8                       Reserved44;

/** Offset 0x0A83 - Hybrid Storage Detection and Configuration Mode
  Enables support for Hybrid storage devices. 0: Disabled; 1: Dynamic Configuration.
  Default is 0: Disabled
  0: Disabled, 1: Dynamic Configuration
**/
  UINT8                       HybridStorageMode;

/** Offset 0x0A84 - Reserved
**/
  UINT8                       Reserved45[93];

/** Offset 0x0AE1 - Enable PS_ON.
  PS_ON is a new C10 state from the CPU on desktop SKUs that enables a lower power
  target that will be required by the California Energy Commission (CEC). When FALSE,
  PS_ON is to be disabled.
  $EN_DIS
**/
  UINT8                       PsOnEnable;

/** Offset 0x0AE2 - Reserved
**/
  UINT8                       Reserved46[211];

/** Offset 0x0BB5 - PCIE Compliance Test Mode
  Compliance Test Mode shall be enabled when using Compliance Load Board.
  $EN_DIS
**/
  UINT8                       CpuPcieComplianceTestMode;

/** Offset 0x0BB6 - Reserved
**/
  UINT8                       Reserved47[106];

/** Offset 0x0C20 - RpPtmBytes
**/
  UINT8                       RpPtmBytes[4];

/** Offset 0x0C24 - Reserved
**/
  UINT8                      Reserved48[95];

/** Offset 0x0C83 - Enable/Disable IGFX PmSupport
  Enable(Default): Enable IGFX PmSupport, Disable: Disable IGFX PmSupport
  $EN_DIS
**/
  UINT8                       PmSupport;

/** Offset 0x0C84 - Reserved
**/
  UINT8                       Reserved49;

/** Offset 0x0C85 - GT Frequency Limit
  0xFF: Auto(Default), 2: 100 Mhz, 3: 150 Mhz, 4: 200 Mhz, 5: 250 Mhz, 6: 300 Mhz,
  7: 350 Mhz, 8: 400 Mhz, 9: 450 Mhz, 0xA: 500 Mhz, 0xB: 550 Mhz, 0xC: 600 Mhz, 0xD:
  650 Mhz, 0xE: 700 Mhz, 0xF: 750 Mhz, 0x10: 800 Mhz, 0x11: 850 Mhz, 0x12:900 Mhz,
  0x13: 950 Mhz, 0x14: 1000 Mhz, 0x15: 1050 Mhz, 0x16: 1100 Mhz, 0x17: 1150 Mhz,
  0x18: 1200 Mhz
  0xFF: Auto(Default), 2: 100 Mhz, 3: 150 Mhz, 4: 200 Mhz, 5: 250 Mhz, 6: 300 Mhz,
  7: 350 Mhz, 8: 400 Mhz, 9: 450 Mhz, 0xA: 500 Mhz, 0xB: 550 Mhz, 0xC: 600 Mhz, 0xD:
  650 Mhz, 0xE: 700 Mhz, 0xF: 750 Mhz, 0x10: 800 Mhz, 0x11: 850 Mhz, 0x12:900 Mhz,
  0x13: 950 Mhz, 0x14: 1000 Mhz, 0x15: 1050 Mhz, 0x16: 1100 Mhz, 0x17: 1150 Mhz,
  0x18: 1200 Mhz
**/
  UINT8                       GtFreqMax;

/** Offset 0x0C86 - Reserved
**/
  UINT8                       Reserved50[24];

/** Offset 0x0C9E - Enable or Disable HWP
  Enable or Disable HWP(Hardware P states) Support. 0: Disable; <b>1: Enable;</b>
  2-3:Reserved
  $EN_DIS
**/
  UINT8                       Hwp;

/** Offset 0x0C9F - Reserved
**/
  UINT8                       Reserved51[8];

/** Offset 0x0CA7 - TCC Activation Offset
  TCC Activation Offset. Offset from factory set TCC activation temperature at which
  the Thermal Control Circuit must be activated. TCC will be activated at TCC Activation
  Temperature, in volts.For SKL Y SKU, the recommended default for this policy is
  <b>10</b>, For all other SKUs the recommended default are <b>0</b>
**/
  UINT8                       TccActivationOffset;

/** Offset 0x0CA8 - Reserved
**/
  UINT8                       Reserved52[34];

/** Offset 0x0CCA - Enable or Disable CPU power states (C-states)
  Enable or Disable CPU power states (C-states). 0: Disable; <b>1: Enable</b>
  $EN_DIS
**/
  UINT8                       Cx;

/** Offset 0x0CCB - Reserved
**/
  UINT8                       Reserved53[157];

/** Offset 0x0D68 - Enable or Disable Fast MSR for IA32_HWP_REQUEST
  Enable or Disable Fast MSR for IA32_HWP_REQUEST. 0: Disable;<b> 1: Enable</b>
  $EN_DIS
**/
  UINT8                       EnableFastMsrHwpReq;

/** Offset 0x0D69 - Reserved
**/
  UINT8                       Reserved54[38];

/** Offset 0x0D8F - Enable LOCKDOWN SMI
  Enable SMI_LOCK bit to prevent writes to the Global SMI Enable bit.
  $EN_DIS
**/
  UINT8                       PchLockDownGlobalSmi;

/** Offset 0x0D90 - Enable LOCKDOWN BIOS Interface
  Enable BIOS Interface Lock Down bit to prevent writes to the Backup Control Register.
  $EN_DIS
**/
  UINT8                       PchLockDownBiosInterface;

/** Offset 0x0D91 - Unlock all GPIO pads
  Force all GPIO pads to be unlocked for debug purpose.
  $EN_DIS
**/
  UINT8                       PchUnlockGpioPads;

/** Offset 0x0D92 - Reserved
**/
  UINT8                       Reserved55[2];

/** Offset 0x0D94 - PCIE RP Ltr Max Snoop Latency
  Latency Tolerance Reporting, Max Snoop Latency.
**/
  UINT16                      PcieRpLtrMaxSnoopLatency[28];

/** Offset 0x0DCC - PCIE RP Ltr Max No Snoop Latency
  Latency Tolerance Reporting, Max Non-Snoop Latency.
**/
  UINT16                      PcieRpLtrMaxNoSnoopLatency[28];

/** Offset 0x0E04 - Reserved
**/
  UINT8                       Reserved56[313];

/** Offset 0x0F3D - LpmStateEnableMask
**/
  UINT8                       LpmStateEnableMask;

/** Offset 0x0F3E - Reserved
**/
  UINT8                      Reserved57[122];
} FSP_S_CONFIG;

/** Fsp S UPD Configuration
**/
typedef struct {

/** Offset 0x0000
**/
  FSP_UPD_HEADER              FspUpdHeader;

/** Offset 0x0020
**/
  FSPS_ARCH_UPD               FspsArchUpd;

/** Offset 0x0040
**/
  FSP_S_CONFIG                FspsConfig;

/** Offset 0x0FB8
**/
  UINT8                       UnusedUpdSpace44[6];

/** Offset 0x0FBE
**/
  UINT16                      UpdTerminator;
} FSPS_UPD;

#pragma pack()

#endif
