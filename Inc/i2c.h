/*
 * ic2.h
 *
 *  Created on: 16. jan. 2023
 *      Author: louiss
 */

#ifndef I2C_H_
#define I2C_H_

#include "stm32f30x_conf.h"

void I2C_Write(uint16_t address, uint8_t reg, uint8_t val);
uint8_t I2C_Read(uint16_t address, uint8_t reg, uint8_t* vals, uint8_t n);
void I2C_init();

#endif /* I2C_H_ */
