package main

import (
	"fmt"

	"github.com/google/go-tpm/tpm2"
	"github.com/xaionaro-go/tpm2-tss/go_tpm2_tss"
)

func main() {
	var ectx *go_tpm2_tss.EsysContext

	pcrIndex := go_tpm2_tss.EsysTr(go_tpm2_tss.EsysTrPcr0)
	fmt.Printf("D: %#+v\n", go_tpm2_tss.TpmlDigestValues{})
	digests := []go_tpm2_tss.TpmlDigestValues{{
		Count: 1,
		Digests: [16]go_tpm2_tss.TpmtHa{
			{
				Hashalg: go_tpm2_tss.TpmiAlgHash(tpm2.AlgSHA1),
				Digest:  go_tpm2_tss.TpmuHa{1, 2, 3, 4},
			},
		},
	}}

	var rc go_tpm2_tss.Tss2Rc

	rc = go_tpm2_tss.EsysInitialize(&ectx, nil, &go_tpm2_tss.Tss2AbiVersion{
		Tsscreator: 1,
		Tssfamily:  2,
		Tsslevel:   1,
		Tssversion: 108,
	})
	if rc != go_tpm2_tss.Tss2RcSuccess {
		panic(fmt.Sprintf("0x%08X", rc))
	}

	rc = go_tpm2_tss.EsysPcrExtend(ectx, pcrIndex, go_tpm2_tss.EsysTrPassword, go_tpm2_tss.EsysTrNone, go_tpm2_tss.EsysTrNone, digests)
	if rc != go_tpm2_tss.Tss2RcSuccess {
		panic(fmt.Sprintf("0x%08X", rc))
	}
}
