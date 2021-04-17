package go_tpm2_tss

import "C"

const (
	Tss2TctiRcLayer  = 10 << Tss2RcLayerShift
	Tss2SysRcLayer   = 8 << Tss2RcLayerShift
	Tss2MuRcLayer    = 9 << Tss2RcLayerShift
	Tss2EsapiRcLayer = 7 << Tss2RcLayerShift
)
