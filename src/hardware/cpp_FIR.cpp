/*******************************************************************************
Vendor: Xilinx 
Associated Filename: cpp_FIR.cpp
Purpose:Vivado HLS Coding Style example 
Device: All 
Revision History: May 30, 2008 - initial release
                                                
*******************************************************************************
Copyright (C) 2013 XILINX, Inc. 

This file contains confidential and proprietary information of Xilinx, Inc. and 
is protected under U.S. and international copyright and other intellectual 
property laws.

DISCLAIMER
This disclaimer is not a license and does not grant any rights to the materials 
distributed herewith. Except as otherwise provided in a valid license issued to 
you by Xilinx, and to the maximum extent permitted by applicable law: 
(1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL FAULTS, AND XILINX 
HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, 
INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT, OR 
FITNESS FOR ANY PARTICULAR PURPOSE; and (2) Xilinx shall not be liable (whether 
in contract or tort, including negligence, or under any other theory of 
liability) for any loss or damage of any kind or nature related to, arising under 
or in connection with these materials, including for any direct, or any indirect, 
special, incidental, or consequential loss or damage (including loss of data, 
profits, goodwill, or any type of loss or damage suffered as a result of any 
action brought by a third party) even if such damage or loss was reasonably 
foreseeable or Xilinx had been advised of the possibility of the same.

CRITICAL APPLICATIONS
Xilinx products are not designed or intended to be fail-safe, or for use in any 
application requiring fail-safe performance, such as life-support or safety 
devices or systems, Class III medical devices, nuclear facilities, applications 
related to the deployment of airbags, or any other applications that could lead 
to death, personal injury, or severe property or environmental damage 
(individually and collectively, "Critical Applications"). Customer assumes the 
sole risk and liability of any use of Xilinx products in Critical Applications, 
subject only to applicable laws and regulations governing limitations on product 
liability. 

THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE AT 
ALL TIMES.

*******************************************************************************/
#include "cpp_FIR.h"

// Top-level function with class instantiated
//data_t cpp_FIR(data_t x)
void cpp_FIR(data_t x, data_t *ret)
  {
    static CFir<coef_t, data_t, acc_t> fir1;

    //cout << fir1;

    //return fir1(x);
    *ret = fir1(x);
  }

#include <stdio.h>
#include <stdlib.h>
#include "cf_stub.h"
extern "C" void _p0_cpp_FIR_0(data_t x, data_t * ret);
extern "C" void _p0_cpp_FIR_0(data_t x, data_t * ret)
{
  switch_to_next_partition(0);
  int start_seq[3];
  start_seq[0] = 0x00000100;
  start_seq[1] = 0x00010100;
  start_seq[2] = 0x00020000;
  cf_request_handle_t _p0_swinst_cpp_FIR_0_cmd;
  cf_send_i(&(_p0_swinst_cpp_FIR_0.cmd_cpp_FIR), start_seq, 3*sizeof(int), &_p0_swinst_cpp_FIR_0_cmd);
  cf_wait(_p0_swinst_cpp_FIR_0_cmd);

  cf_send_i(&(_p0_swinst_cpp_FIR_0.x), &x, 4, &_p0_request_0);

  cf_receive_i(&(_p0_swinst_cpp_FIR_0.ret), ret, 4, &_p0_cpp_FIR_0_num_ret, &_p0_request_1);

  cf_wait(_p0_request_0);
  cf_wait(_p0_request_1);
}


