// License: CC-0

// WARNING: This file has automatically been generated on Sat, 17 Apr 2021 22:05:09 IST.
// Code generated by https://git.io/c-for-go. DO NOT EDIT.

#include "_cgo_export.h"
#include "cgo_helpers.h"

unsigned int TSS2_TCTI_TRANSMIT_FCN_3fb81c0d(TSS2_TCTI_CONTEXT* tctiContext, unsigned long int size, unsigned char* command) {
	return tss2TctiTransmitFcn3FB81C0D(tctiContext, size, command);
}

unsigned int TSS2_TCTI_RECEIVE_FCN_f4548f13(TSS2_TCTI_CONTEXT* tctiContext, unsigned long int* size, unsigned char* response, int timeout) {
	return tss2TctiReceiveFcnF4548F13(tctiContext, size, response, timeout);
}

void TSS2_TCTI_FINALIZE_FCN_f5e8712e(TSS2_TCTI_CONTEXT* tctiContext) {
	tss2TctiFinalizeFcnF5E8712E(tctiContext);
}

unsigned int TSS2_TCTI_CANCEL_FCN_900241eb(TSS2_TCTI_CONTEXT* tctiContext) {
	return tss2TctiCancelFcn900241EB(tctiContext);
}

unsigned int TSS2_TCTI_GET_POLL_HANDLES_FCN_d9753da9(TSS2_TCTI_CONTEXT* tctiContext, TSS2_TCTI_POLL_HANDLE* handles, unsigned long int* num_handles) {
	return tss2TctiGetPollHandlesFcnD9753DA9(tctiContext, handles, num_handles);
}

unsigned int TSS2_TCTI_SET_LOCALITY_FCN_47c1ecda(TSS2_TCTI_CONTEXT* tctiContext, unsigned char locality) {
	return tss2TctiSetLocalityFcn47C1ECDA(tctiContext, locality);
}

unsigned int TSS2_TCTI_MAKE_STICKY_FCN_de2406fc(TSS2_TCTI_CONTEXT* tctiContext, unsigned int* handle, unsigned char sticky) {
	return tss2TctiMakeStickyFcnDE2406FC(tctiContext, handle, sticky);
}

unsigned int TSS2_TCTI_INIT_FUNC_a5effe61(TSS2_TCTI_CONTEXT* tctiContext, unsigned long int* size, char* config) {
	return tss2TctiInitFuncA5EFFE61(tctiContext, size, config);
}

TSS2_TCTI_INFO* TSS2_TCTI_INFO_FUNC_3ab67cd0() {
	return tss2TctiInfoFunc3AB67CD0();
}

char* TSS2_RC_HANDLER_c80e0a42(unsigned int rc) {
	return tss2RcHandlerC80E0A42(rc);
}

