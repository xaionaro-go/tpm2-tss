all: generate hacks fmt

generate:
	c-for-go --ccincl go-tpm2-tss.yaml

hacks:
	sed -r -e 's/Unsafe\.Pointer/UnsafePointer/' -e 's/chandles C\.TSS2_TCTI_POLL_HANDLE/chandles *C.TSS2_TCTI_POLL_HANDLE/g' -i go_tpm2_tss/cgo_helpers.go
	sed -r -e 's/TSS2_TCTI_GET_POLL_HANDLES_FCN_d9753da9\(TSS2_TCTI_CONTEXT\* tctiContext, void\* handles, unsigned long int\* num_handles\)/TSS2_TCTI_GET_POLL_HANDLES_FCN_d9753da9(TSS2_TCTI_CONTEXT* tctiContext, TSS2_TCTI_POLL_HANDLE* handles, unsigned long int* num_handles)/g' -i go_tpm2_tss/cgo_helpers.[ch]

fmt:
	go fmt ./go_tpm2_tss/...
