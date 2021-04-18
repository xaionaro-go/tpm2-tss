package main

import (
	"fmt"

	"github.com/google/go-tpm/tpm2"
	"github.com/xaionaro-go/tpm2-tss/cgo_tpm2_tss"
)

func main() {
	var ectx *cgo_tpm2_tss.EsysContext

	pcrIndex := cgo_tpm2_tss.EsysTr(cgo_tpm2_tss.EsysTrPcr0)
	digests := []cgo_tpm2_tss.TpmlDigestValues{{
		Count: 1,
		Digests: [16]cgo_tpm2_tss.TpmtHa{
			{
				Hashalg: cgo_tpm2_tss.TpmiAlgHash(tpm2.AlgSHA1),
				Digest:  cgo_tpm2_tss.TpmuHa{1, 2, 3, 4},
			},
		},
	}}

	var rc cgo_tpm2_tss.Tss2Rc
	var tcti *cgo_tpm2_tss.Tss2TctiContext

	rc = cgo_tpm2_tss.Tss2TctildrInitialize("", &tcti)
	if rc != cgo_tpm2_tss.Tss2RcSuccess {
		panic(fmt.Sprintf("0x%08X", rc))
	}

	rc = cgo_tpm2_tss.EsysInitialize(&ectx, tcti, &cgo_tpm2_tss.Tss2AbiVersion{
		Tsscreator: 1,
		Tssfamily:  2,
		Tsslevel:   1,
		Tssversion: 108,
	})
	if rc != cgo_tpm2_tss.Tss2RcSuccess {
		panic(fmt.Sprintf("0x%08X", rc))
	}

	rc = cgo_tpm2_tss.EsysPcrExtend(ectx, pcrIndex, cgo_tpm2_tss.EsysTrPassword, cgo_tpm2_tss.EsysTrNone, cgo_tpm2_tss.EsysTrNone, digests)
	if rc != cgo_tpm2_tss.Tss2RcSuccess {
		panic(fmt.Sprintf("0x%08X", rc))
	}

	fmt.Println("SUCCESS")
}
