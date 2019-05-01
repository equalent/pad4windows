/*
libPad (PS3's DUALSHOCK 3)
Contains modified code from https://github.com/HACKERCHANNEL/PSL1GHT/blob/master/include/io/pad.h
*/

#include <stdint.h>

#define MAX_PADS		127
#define MAX_PORT_NUM	7

typedef struct CellPadInfo
{
	uint32_t max;
	uint32_t connected;
	uint32_t info;
	uint16_t vendor_id[MAX_PADS];
	uint16_t product_id[MAX_PADS];
	uint8_t  status[MAX_PADS];
} CellPadInfo;

typedef struct CellPadInfo2
{
	uint32_t max;
	uint32_t connected;
	uint32_t info;
    uint32_t port_status[MAX_PORT_NUM];
    uint32_t port_setting[MAX_PORT_NUM];
    uint32_t device_capability[MAX_PORT_NUM];
    uint32_t device_type[MAX_PORT_NUM];
} CellPadInfo2;

#define PAD_MAX_CODES 64
typedef struct CellPadData
{
	int len;
	union{
		uint16_t button[PAD_MAX_CODES];
		struct {
			uint16_t zeroes;
			unsigned int				:  8;
			unsigned int seven 			:  4;
			unsigned int halflen 		:  4;
			unsigned int				:  8;
			unsigned int BTN_LEFT 		:  1;
			unsigned int BTN_DOWN 		:  1;
			unsigned int BTN_RIGHT 		:  1;
			unsigned int BTN_UP 		:  1;
			unsigned int BTN_START 		:  1;
			unsigned int BTN_R3 		:  1;
			unsigned int BTN_L3 		:  1;
			unsigned int BTN_SELECT		:  1;
			unsigned int				:  8;
			unsigned int BTN_SQUARE 	:  1;
			unsigned int BTN_CROSS 		:  1;
			unsigned int BTN_CIRCLE 	:  1;
			unsigned int BTN_TRIANGLE	:  1;
			unsigned int BTN_R1 		:  1;
			unsigned int BTN_L1 		:  1;
			unsigned int BTN_R2 		:  1;
			unsigned int BTN_L2			:  1;
			unsigned int ANA_R_H		: 16;
			unsigned int ANA_R_V		: 16;
			unsigned int ANA_L_H		: 16;
			unsigned int ANA_L_V		: 16;
			unsigned int PRE_RIGHT		: 16;
			unsigned int PRE_LEFT		: 16;
			unsigned int PRE_UP			: 16;
			unsigned int PRE_DOWN		: 16;
			unsigned int PRE_TRIANGLE	: 16;
			unsigned int PRE_CIRCLE		: 16;
			unsigned int PRE_CROSS		: 16;
			unsigned int PRE_SQUARE		: 16;
			unsigned int PRE_L1			: 16;
			unsigned int PRE_R1			: 16;
			unsigned int PRE_L2			: 16;
			unsigned int PRE_R2			: 16;
			unsigned int SENSOR_X		: 16;
			unsigned int SENSOR_Y		: 16;
			unsigned int SENSOR_Z		: 16;
			unsigned int SENSOR_G		: 16;
			uint8_t reserved[80];
		};
	};
} CellPadData;

typedef struct CellPadInfo2
{
	uint32_t max;
	uint32_t connected;
	uint32_t info;
    uint32_t port_status[MAX_PORT_NUM];
    uint32_t port_setting[MAX_PORT_NUM];
    uint32_t device_capability[MAX_PORT_NUM];
    uint32_t device_type[MAX_PORT_NUM];
} CellPadInfo2;

#define PAD_CAPABILITY_INFO_MAX 32
typedef struct CellPadCapabilityInfo
{
	union {
		uint32_t info[PAD_CAPABILITY_INFO_MAX];
		struct {
			unsigned int 				: 27;
			unsigned int has_vibrate	:  1;
			unsigned int has_hps		:  1;
			unsigned int has_sensors	:  1;
			unsigned int has_pressure	:  1;
			unsigned int ps3spec		:  1;
			uint32_t reserved[PAD_CAPABILITY_INFO_MAX-1];
		};
	};
} CellPadCapabilityInfo;

#define PAD_ACTUATOR_MAX	(2)
typedef struct CellPadActParam
{
	union {
		uint8_t motor[PAD_ACTUATOR_MAX];
		struct {
			uint8_t small_motor;
			uint8_t large_motor;
		};
	};
	uint8_t reserved[6];
} CellPadActParam;

typedef struct CellPadPeriphInfo
{
	uint32_t max;
	uint32_t connected;
	uint32_t info;
    uint32_t port_status[MAX_PORT_NUM];
    uint32_t port_setting[MAX_PORT_NUM];
    uint32_t device_capability[MAX_PORT_NUM];
    uint32_t device_type[MAX_PORT_NUM];
    uint32_t pclass_type[MAX_PORT_NUM];
    uint32_t pclass_profile[MAX_PORT_NUM];
} CellPadPeriphInfo;

typedef struct CellPadPeriphData
{
  uint32_t pclass_type;
  uint32_t pclass_profile;
  int len;
  uint16_t button[PAD_MAX_CODES];
} CellPadPeriphData;

int cellPadClearBuf(unsigned int port_no);
int cellPadEnd(void);
int cellPadGetCapabilityInfo(const uint32_t port, CellPadCapabilityInfo* pad_capinfo);
int cellPadGetData(const uint32_t port, CellPadData* pad_data);
int cellPadGetInfo(CellPadInfo* pad_info);
int cellPadGetInfo2(CellPadInfo2* pad_info);
int cellPadInfoPressMode(const uint32_t port);
int cellPadInfoSensorMode(const uint32_t port);
int cellPadInit(unsigned int max_connect);
int cellPadSetActDirect(const uint32_t port, const CellPadActParam* pad_actparam);
int cellPadSetPortSetting(const uint32_t port, const uint32_t setting);
int cellPadSetPressMode(const uint32_t port, const uint32_t mode);
int cellPadSetSensorMode(const uint32_t port, const uint32_t mode);

#define PAD_CHECK(A, B) (((A>>B)&0x1) == 1)

/* NOT IMPLEMENTED INLINE FUNCTIONS! */
inline bool cellPadHasPS3Spec(const uint32_t port);
inline bool cellPadHasPressure(const uint32_t port);
inline bool cellPadHasSensor(const uint32_t port);
inline bool cellPadHasHPS(const uint32_t port);
inline bool cellPadHasVibrate(const uint32_t port);