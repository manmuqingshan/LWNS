/*
 * lwns_adapter_csma_mac.h
 *
 *  Created on: Jul 19, 2021
 *      Author: WCH
 */

#ifndef _LWNS_ADAPTER_CSMA_MAC_H_
#define _LWNS_ADAPTER_CSMA_MAC_H_

#ifdef __cplusplus
extern "C"
{
#endif

#define LWNS_USE_CSMA_MAC               0  //是否使能模仿csma的mac协议，注意只能使能一个mac层协议。

#if LWNS_USE_CSMA_MAC

#include "WCH_LWNS_LIB.h"

struct csma_mac_phy_manage_struct{
    struct csma_mac_phy_manage_struct* next;
    u8* data;
};//模拟csma mac层发送管理结构体

typedef enum {
    BLE_PHY_MANAGE_STATE_FREE = 0,
    BLE_PHY_MANAGE_STATE_RECEIVED,
    BLE_PHY_MANAGE_STATE_WAIT_SEND,
    BLE_PHY_MANAGE_STATE_SENDING,
} BLE_PHY_MANAGE_STATE_t;


#define LWNS_ENCRYPT_ENABLE                    1  //是否使能加密

#define LWNS_ADDR_USE_BLE_MAC             1  //是否使用蓝牙硬件的mac地址作为库地址

#define LWNS_NEIGHBOR_MAX_NUM             8   //最大邻居数量

#define LWNS_MAC_TRANSMIT_TIMES           2   //一次发送，调用硬件发送几次
#define LWNS_MAC_PERIOD_MS                20  //mac发送接收检测周期，如果有需要发送的数据包，则开始随机延迟检测冲突。//为(1000/HTIMER_SECOND_NUM)

#define LWNS_MAC_SEND_DELAY_MAX_625US     LWNS_NEIGHBOR_MAX_NUM  //随机延迟，该值越小，越容易出现错误，推荐大一些，8测试概率还可以。

#define BLE_PHY_ONE_PACKET_MAX_625US      5

#define LWNS_MAC_SEND_PACKET_MAX_NUM      8   //发送链表最多支持几个数据包等待发送

#define LWNS_MAC_SEND_DELAY_MAX_TIMES     LWNS_NEIGHBOR_MAX_NUM/2   //在发送被取消，延迟几次后，不再随机等待，立刻发送

#define LLE_MODE_ORIGINAL_RX                        (0x80)  //如果配置LLEMODE时加上此宏，则接收第一字节为原始数据（原来为RSSI）

extern void RF_Init( void );

void lwns_init(void);

//RF_TX和RF_RX所用的类型，可以修改，不推荐改
#define USER_RF_RX_TX_TYPE 0xff

//receive process evt
#define LWNS_PHY_RX_OPEN_EVT          1
//send process evt
#define LWNS_PHY_PERIOD_EVT           1
#define LWNS_PHY_OUTPUT_EVT           2
#define LWNS_PHY_OUTPUT_FINISH_EVT    4

#define LWNS_PHY_OUTPUT_TIMEOUT_MS        5

#endif  /* LWNS_USE_CSMA_MAC */

#ifdef __cplusplus
}
#endif

#endif /* _LWNS_ADAPTER_CSMA_MAC_H_ */
