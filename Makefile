all: generate hacks fmt

generate:
	c-for-go --ccincl go-tpm2-tss.yaml

hacks:
	sed -r -e 's/Unsafe\.Pointer/UnsafePointer/' -i go_tpm2_tss/cgo_helpers.go go_tpm2_tss/go_tpm2_tss.go
	sed -r -e 's/chandles C\.TSS2_TCTI_POLL_HANDLE/chandles *C.TSS2_TCTI_POLL_HANDLE/g' -i go_tpm2_tss/cgo_helpers.go
	#sed -r -e "s/import \"C\"/import \"C\"\nimport (\"fmt\"\n\"runtime\"\n\"sync\"\n\"unsafe\"\n)/g" -i  go_tpm2_tss/cgo_helpers.go
	sed -r -e 's/TSS2_TCTI_GET_POLL_HANDLES_FCN_d9753da9\(TSS2_TCTI_CONTEXT\* tctiContext, void\* handles, unsigned long int\* num_handles\)/TSS2_TCTI_GET_POLL_HANDLES_FCN_d9753da9(TSS2_TCTI_CONTEXT* tctiContext, TSS2_TCTI_POLL_HANDLE* handles, unsigned long int* num_handles)/g' -i go_tpm2_tss/cgo_helpers.[ch]
	sed -r -e 's/Name           \*string/Name           string/' -e 's/Description    \*string/Description    string/g' -e 's/ConfigHelp     \*string/ConfigHelp     string/g' -i go_tpm2_tss/types.go
	#sed -r -e 's/__ret := C.Tss2_RC_SetHandler\(clayer, cname, chandler\)/__ret := C.Tss2_RC_SetHandler(clayer, cname, chandler); __v := *(*Tss2RcHandler)(unsafe.Pointer(\&__ret))/g' -i go_tpm2_tss/go_tpm2_tss.go
	sed -r -e 's/__ret := C.Esys_GetPollHandles\(cesysContext, chandles, ccount\)/__ret := C.Esys_GetPollHandles(cesysContext, (**C.TSS2_TCTI_POLL_HANDLE)(unsafe.Pointer(chandles)), ccount)/g' -e 's/\) \*string \{/) string {/g' -i go_tpm2_tss/go_tpm2_tss.go
	sed -r -e 's/ret, _ := unpackArgSTss2TctiInfo\(ret3ab67cd0\)/hdr := \&sliceHeader{Data: unsafe.Pointer(ret3ab67cd0)}; if ret3ab67cd0 != nil { hdr.Len = 1; hdr.Cap = 1 }; ret, _ := unpackArgSTss2TctiInfo(*(*[]Tss2TctiInfo)((unsafe.Pointer)(hdr)))/g' -i go_tpm2_tss/cgo_helpers.go
	sed -r -e 's/\(\(Tpm2Hc\)\((.*) << Tpm2HrShift\)\)/((Tpm2Hc)(\1) << Tpm2HrShift)/g' -i go_tpm2_tss/const.go
	sed -r -e 's/conf \*string/conf string/g' -e 's/name \*string, conf \*string/name string, conf string/' -e 's/name \*string/name string/g' -i go_tpm2_tss/go_tpm2_tss.go
	sed -r -e 's/todolist \[\]\*TpmlAlg/todolist *[]TpmlAlg/g' -e 's/unsafe.Pointer\(&todolist\)/unsafe.Pointer(todolist)/g' -e 's/, ctodolist([)])/, \&ctodolist\1/g' -e 's/Tss2_Sys_IncrementalSelfTest_Complete\(csyscontext, &ctodolist\)/Tss2_Sys_IncrementalSelfTest_Complete(csyscontext, ctodolist)/g' -i go_tpm2_tss/go_tpm2_tss.go
	#sed -r -e 's/c(curveid|eventdata), c(digest|parameter)s/c\1, \&c\2s/g' -i go_tpm2_tss/go_tpm2_tss.go
	sed -r -e 's/s \[\]\*/s *[]/g' -i go_tpm2_tss/go_tpm2_tss.go
	sed -r -e '/ccurveid/{n; s/unsafe.Pointer\(&([a-z]*)s\)/unsafe.Pointer(\1s)/g}' -e '/cesyscontext/{n; s/unsafe.Pointer\(&([a-z]*)s\)/unsafe.Pointer(\1s)/g}' -i go_tpm2_tss/go_tpm2_tss.go
	sed -r -e '/copy.*unsafe.Pointer\(parameters\)/{n; s/, cparameters/, \&cparameters/}' -i go_tpm2_tss/go_tpm2_tss.go

fmt:
	go fmt ./go_tpm2_tss/...
