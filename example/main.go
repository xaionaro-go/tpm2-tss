package main

import (
	"fmt"

	"github.com/google/go-tpm/tpm2"
	"github.com/xaionaro-go/tpm2-tss/go_tpm2_tss"
)

func main() {
	var ectx *go_tpm2_tss.EsysContext

	pcrIndex := go_tpm2_tss.EsysTr(go_tpm2_tss.EsysTrPcr0)
	digests := []go_tpm2_tss.TpmlDigestValues{{
		Count: 1,
		Digests: [16]go_tpm2_tss.TpmtHa{
			{
				Hashalg: go_tpm2_tss.TpmiAlgHash(tpm2.AlgSHA1),
				Digest:  go_tpm2_tss.TpmuHa{1, 2, 3, 4},
			},
		},
	}}

	var tctx *go_tpm2_tss.Tss2TctiContext
	rc := go_tpm2_tss.Tss2TctildrInitialize("test", &tctx)
	if rc != go_tpm2_tss.Tss2RcSuccess {
		panic(fmt.Sprintf("0x%08X", rc))
	}

	go_tpm2_tss.EsysInitialize(&ectx, tctx, &go_tpm2_tss.Tss2AbiVersion{
		Tsscreator: 0,
		Tssfamily:  0,
		Tsslevel:   0,
		Tssversion: 0,
	})

	rc = go_tpm2_tss.EsysPcrExtend(ectx, pcrIndex, go_tpm2_tss.EsysTrPassword, go_tpm2_tss.EsysTrNone, go_tpm2_tss.EsysTrNone, digests)
	if rc != go_tpm2_tss.Tss2RcSuccess {
		panic(fmt.Sprintf("0x%08X", rc))
	}
}
