 /** @file lightanchor_detector.h
 *  @brief Definitions for the lightanchor detector library
 * 
 *  Use apriltag library to implement a lightanchors detector
 *  More details: (to be available)
 *
 * Copyright (C) Wiselab CMU. 
 * @date July, 2020
 */

#ifndef _LIGHTANCHORS_DETECT_
#define _LIGHTANCHORS_DETECT_
#include "apriltag.h"
#include "common/zarray.h"

/* declare functions in apriltag.c that we need as extern */
extern zarray_t *apriltag_quad_thresh(apriltag_detector_t *td, image_u8_t *im);
void quad_destroy(struct quad *quad);

/**
 * Use apriltag library to detect quads from an image and 
 * return an array of these (struct quad). 
 *
 * Caller *must free* returned array with quads_destroy()
 *
 * This is step 1 of the apriltag detector: 
 *  https://github.com/AprilRobotics/apriltag/blob/master/apriltag.c
 *
 * @param *td an initialized apriltag detector
 * @param *im_orig grayscale image to perform the detection on
 * 
 * @return z_array of struct quad
 */
zarray_t *detect_quads(apriltag_detector_t *td, image_u8_t *im_orig);


/**
 * Free an array of quads
 *
 * @param *quads z_array of quads
 *
 * @return number of quads freed
 */
int quads_destroy(zarray_t *quads);

#endif