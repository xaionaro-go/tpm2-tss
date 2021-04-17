for f in $( (grep -RIn '\*\*' go_tpm2_tss/ | grep func | grep "Tpm2b\|TpmsContext\|TpmsTimeInfo\|TpmsCapabilityData"; grep -RIn ' \*\[\]' go_tpm2_tss/ | grep func ) | sed -e 's/.*func //' -e 's/(.*//g' ); do
  grep " $f " go_tpm2_tss/go_tpm2_tss.go
done | grep tss2/ | awk '{print $7}' | awk -F ':' '{print "sed \""$2"q;d\" c/include/" $1}'  | bash | tr "(" "|" | tr -d "\n"
echo