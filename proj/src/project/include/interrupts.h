#ifndef INTERRUPS_H
#define INTERRUPS_H

#include "libs.h"

/**
 * @brief subscribes all devices
 * 
 * @return int returns 0 in case of success and 1 otherwise
 */
int (subscribeAll)(void);

/**
 * @brief unsubscribes all devices
 * 
 * @return int returns 0 in case of success and 1 otherwise
 */
int (unsubscribeAll)(void);

#endif
