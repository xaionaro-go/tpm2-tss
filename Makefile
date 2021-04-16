all:
	c-for-go --ccincl go-tpm2-tss.yaml
	sed -e 's/Unsafe\.Pointer/UnsafePointer/' -i go_tpm2_tss/cgo_helpers.go
	go fmt ./go_tpm2_tss/...
