// License: CC-0

// WARNING: This file has automatically been generated on Sat, 17 Apr 2021 00:39:05 IST.
// Code generated by https://git.io/c-for-go. DO NOT EDIT.

#include "tss2/tss2_common.h"
#include "tss2/tss2_esys.h"
#include "tss2/tss2_fapi.h"
#include "tss2/tss2_mu.h"
#include "tss2/tss2_rc.h"
#include "tss2/tss2_sys.h"
#include "tss2/tss2_tcti_device.h"
#include "tss2/tss2_tcti.h"
#include "tss2/tss2_tctildr.h"
#include "tss2/tss2_tcti_mssim.h"
#include "tss2/tss2_tcti_tbs.h"
#include "tss2/tss2_tpm2_types.h"
#include <stdlib.h>
#pragma once

#define __CGOGEN 1

// TSS2_TCTI_TRANSMIT_FCN_3fb81c0d is a proxy for callback TSS2_TCTI_TRANSMIT_FCN.
unsigned int TSS2_TCTI_TRANSMIT_FCN_3fb81c0d(TSS2_TCTI_CONTEXT* tctiContext, unsigned long int size, unsigned char* command);

// TSS2_TCTI_RECEIVE_FCN_f4548f13 is a proxy for callback TSS2_TCTI_RECEIVE_FCN.
unsigned int TSS2_TCTI_RECEIVE_FCN_f4548f13(TSS2_TCTI_CONTEXT* tctiContext, unsigned long int* size, unsigned char* response, int timeout);

// TSS2_TCTI_FINALIZE_FCN_f5e8712e is a proxy for callback TSS2_TCTI_FINALIZE_FCN.
void TSS2_TCTI_FINALIZE_FCN_f5e8712e(TSS2_TCTI_CONTEXT* tctiContext);

// TSS2_TCTI_CANCEL_FCN_900241eb is a proxy for callback TSS2_TCTI_CANCEL_FCN.
unsigned int TSS2_TCTI_CANCEL_FCN_900241eb(TSS2_TCTI_CONTEXT* tctiContext);

// TSS2_TCTI_GET_POLL_HANDLES_FCN_d9753da9 is a proxy for callback TSS2_TCTI_GET_POLL_HANDLES_FCN.
unsigned int TSS2_TCTI_GET_POLL_HANDLES_FCN_d9753da9(TSS2_TCTI_CONTEXT* tctiContext, void* handles, unsigned long int* num_handles);

// TSS2_TCTI_SET_LOCALITY_FCN_47c1ecda is a proxy for callback TSS2_TCTI_SET_LOCALITY_FCN.
unsigned int TSS2_TCTI_SET_LOCALITY_FCN_47c1ecda(TSS2_TCTI_CONTEXT* tctiContext, unsigned char locality);

// TSS2_TCTI_MAKE_STICKY_FCN_de2406fc is a proxy for callback TSS2_TCTI_MAKE_STICKY_FCN.
unsigned int TSS2_TCTI_MAKE_STICKY_FCN_de2406fc(TSS2_TCTI_CONTEXT* tctiContext, unsigned int* handle, unsigned char sticky);

// TSS2_TCTI_INIT_FUNC_a5effe61 is a proxy for callback TSS2_TCTI_INIT_FUNC.
unsigned int TSS2_TCTI_INIT_FUNC_a5effe61(TSS2_TCTI_CONTEXT* tctiContext, unsigned long int* size, char* config);

// TSS2_TCTI_INFO_FUNC_3ab67cd0 is a proxy for callback TSS2_TCTI_INFO_FUNC.
TSS2_TCTI_INFO* TSS2_TCTI_INFO_FUNC_3ab67cd0();

// Fapi_CB_Auth_4bc69268 is a proxy for callback Fapi_CB_Auth.
unsigned int Fapi_CB_Auth_4bc69268(FAPI_CONTEXT* context, char* description, char** auth, void* userData);

// Fapi_CB_Branch_a8bbee51 is a proxy for callback Fapi_CB_Branch.
unsigned int Fapi_CB_Branch_a8bbee51(FAPI_CONTEXT* context, char* description, char** branchNames, unsigned long int numBranches, unsigned long int* selectedBranch, void* userData);

// Fapi_CB_Sign_2c66b3cf is a proxy for callback Fapi_CB_Sign.
unsigned int Fapi_CB_Sign_2c66b3cf(FAPI_CONTEXT* context, char* description, char* publicKey, char* publicKeyHint, unsigned int hashAlg, unsigned char* dataToSign, unsigned long int dataToSignSize, unsigned char** signature, unsigned long int* signatureSize, void* userData);

// Fapi_CB_PolicyAction_d83965a7 is a proxy for callback Fapi_CB_PolicyAction.
unsigned int Fapi_CB_PolicyAction_d83965a7(FAPI_CONTEXT* context, char* action, void* userData);

// __compar_fn_t_60e030d6 is a proxy for callback __compar_fn_t.
int __compar_fn_t_60e030d6(void* arg0, void* arg1);

// TSS2_RC_HANDLER_c80e0a42 is a proxy for callback TSS2_RC_HANDLER.
char* TSS2_RC_HANDLER_c80e0a42(unsigned int rc);

