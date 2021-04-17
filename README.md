<p xmlns:dct="http://purl.org/dc/terms/" xmlns:vcard="http://www.w3.org/2001/vcard-rdf/3.0#">
  <a rel="license"
     href="http://creativecommons.org/publicdomain/zero/1.0/">
    <img src="http://i.creativecommons.org/p/zero/1.0/88x31.png" style="border-style: none;" alt="CC0" />
  </a>
  <br />
  To the extent possible under law,
  <a rel="dct:publisher"
     href="https://github.com/xaionaro/">
    <span property="dct:title">Dmitrii Okunev</span></a>
  has waived all copyright and related or neighboring rights to
  "<span property="dct:title">CGo bindings for tpm2-tss</span>.
This work is published from:
<span property="vcard:Country" datatype="dct:ISO3166"
      content="IE" about="https://github.com/xaionaro-go/tpm2-tss">
  Ireland</span>".
</p>

[![GoDoc](https://godoc.org/github.com/xaionaro-go/tpm2-tss?status.svg)](https://pkg.go.dev/github.com/xaionaro-go/tpm2-tss/go_tpm2_tss?tab=doc)

# About

This is very stupid CGo bindings for [tpm2-tss](https://github.com/tpm2-software/tpm2-tss).

# Prepare

Currently, the package expects libtss2 of version 2.3.2 be installed.

```sh
apt-get install -y libtss2-dev
go get -d github.com/xaionaro-go/tpm2-tss/...
cd $(go env GOPATH)/src/github.com/xaionaro-go/tpm2-tss
git submodule update --init --recursive
```

# Example

```go
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

	var rc go_tpm2_tss.Tss2Rc
	var tcti *go_tpm2_tss.Tss2TctiContext

	rc = go_tpm2_tss.Tss2TctildrInitialize("", &tcti)
	if rc != go_tpm2_tss.Tss2RcSuccess {
		panic(fmt.Sprintf("0x%08X", rc))
	}

	rc = go_tpm2_tss.EsysInitialize(&ectx, tcti, &go_tpm2_tss.Tss2AbiVersion{
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

	fmt.Println("SUCCESS")
}
```
Result:
```
xaionaro@void:~/go/src/github.com/xaionaro-go/tpm2-tss$ sudo tpm2_pcrread 2>/dev/null | head -2
sha1:
  0 : 0x225D4733A7F538514995ADFA5CFE07590E3A6EB2
xaionaro@void:~/go/src/github.com/xaionaro-go/tpm2-tss$ go build -o /tmp/bin ./example/ && sudo /tmp/bin 2>/dev/null
SUCCESS
xaionaro@void:~/go/src/github.com/xaionaro-go/tpm2-tss$ sudo tpm2_pcrread 2>/dev/null | head -2
sha1:
  0 : 0xFD3E2E5BC01251885EB591FF0D73E55A9645D493
```

# Work in progress

These functions are not binded yet:
* Esys_GetCapability
* Esys_GetCapability_Finish
* Esys_ReadClock
* Esys_ReadClock_Finish
* Esys_ContextSave
* Esys_ContextSave_Finish
* Esys_IncrementalSelfTest
* Esys_IncrementalSelfTest_Finish
* Esys_ECC_Parameters
* Esys_ECC_Parameters_Finish
* Esys_TR_GetName
* Esys_TRSess_GetNonceTPM
* Esys_GetTestResult
* Esys_GetTestResult_Finish
* Esys_Create
* Esys_Create_Finish
* Esys_ReadPublic
* Esys_ReadPublic_Finish
* Esys_ActivateCredential
* Esys_ActivateCredential_Finish
* Esys_MakeCredential
* Esys_MakeCredential_Finish
* Esys_Unseal
* Esys_Unseal_Finish
* Esys_ObjectChangeAuth
* Esys_ObjectChangeAuth_Finish
* Esys_CreateLoaded
* Esys_CreateLoaded_Finish
* Esys_Duplicate
* Esys_Duplicate_Finish
* Esys_Rewrap
* Esys_Rewrap_Finish
* Esys_Import
* Esys_Import_Finish
* Esys_RSA_Encrypt
* Esys_RSA_Encrypt_Finish
* Esys_RSA_Decrypt
* Esys_RSA_Decrypt_Finish
* Esys_ECDH_KeyGen
* Esys_ECDH_KeyGen_Finish
* Esys_ECDH_ZGen
* Esys_ECDH_ZGen_Finish
* Esys_ZGen_2Phase
* Esys_ZGen_2Phase_Finish
* Esys_EncryptDecrypt
* Esys_EncryptDecrypt_Finish
* Esys_EncryptDecrypt2
* Esys_EncryptDecrypt2_Finish
* Esys_Hash
* Esys_Hash_Finish
* Esys_HMAC
* Esys_HMAC_Finish
* Esys_GetRandom
* Esys_GetRandom_Finish
* Esys_SequenceComplete
* Esys_SequenceComplete_Finish
* Esys_Certify
* Esys_Certify_Finish
* Esys_CertifyCreation
* Esys_CertifyCreation_Finish
* Esys_Quote
* Esys_Quote_Finish
* Esys_GetSessionAuditDigest
* Esys_GetSessionAuditDigest_Finish
* Esys_GetCommandAuditDigest
* Esys_GetCommandAuditDigest_Finish
* Esys_GetTime
* Esys_GetTime_Finish
* Esys_Commit
* Esys_Commit_Finish
* Esys_EC_Ephemeral
* Esys_EC_Ephemeral_Finish
* Esys_VerifySignature
* Esys_Sign
* Esys_PolicySigned
* Esys_PolicySigned_Finish
* Esys_PolicySecret
* Esys_PolicySecret_Finish
* Esys_PolicyGetDigest
* Esys_PolicyGetDigest_Finish
* Esys_CreatePrimary
* Esys_CreatePrimary_Finish
* Esys_FieldUpgradeData
* Esys_FirmwareRead
* Esys_FirmwareRead_Finish
* Esys_NV_ReadPublic
* Esys_NV_ReadPublic_Finish
* Esys_NV_Read
* Esys_NV_Read_Finish
* Esys_NV_Certify
* Esys_NV_Certify_Finish
* Esys_Vendor_TCG_Test
* Esys_Vendor_TCG_Test_Finish
* Esys_EventSequenceComplete
* Esys_PCR_Event*
* Esys_PCR_Read
* Tss2_Tcti_Tbs_Init
* Tss2_MU_TPMU_ENCRYPTED_SECRET_Marshal
* Tss2_MU_TPMU_ENCRYPTED_SECRET_Unmarshal

If you need any of these functions then create an issue. I'll take a look if
it is possible to easily add the function :)
