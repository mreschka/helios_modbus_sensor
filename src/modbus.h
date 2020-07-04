/*
    modbus.h - handling content of modbus frames
    Copyright (C) 2018, M. Brandt>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef MODBUS_H
#define	MODBUS_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <stdbool.h>

#define MODBUS_MAX_FRAMELENGTH (64u)

#define MODBUS_FRAME_TIMEOUT   (1100000ul)

#define MAX_TEMP_SENSCOUNT (8u)
#define TEMP_MASK  ((1u<<MAX_TEMP_SENSCOUNT) - 1u)

#define MAX_VOC_SENSCOUNT (8u)
#define VOC_MASK  ((1u<<MAX_VOC_SENSCOUNT) - 1u)

#define MAX_CO2_SENSCOUNT (10u - MAX_VOC_SENSCOUNT)
#define CO2_MASK   ((1u<<MAX_CO2_SENSCOUNT) - 1u)

#define NUM_SENSORS (MAX_TEMP_SENSCOUNT + MAX_VOC_SENSCOUNT + MAX_CO2_SENSCOUNT)

void modbus_init();
void setReadCRC(uint8_t index);
void setWriteCRC();
void SendWriteAnswer(uint8_t addr, uint8_t len);
void SendReadAnswer(uint8_t addr);
void updateValues(void);
void updateValuesTrigger(void);
void UpdateReadAnswerFoo(uint8_t addr, uint8_t foo);
uint8_t addr2index(uint8_t addr);

#ifdef	__cplusplus
}
#endif

#endif	/* KNX_H */

