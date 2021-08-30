Notes

Docker <br>
docker build buildenv -t myos-buildenv <br>

linux <br>
docker run --rm -it -v $PWD:/root/env myos-buildenv <br>

make build-x86_64 <br>

exit docker container <br>
qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso <br>

; print 'OK' <br>
mov dword [0xb8000], 0x2f4b2f4f <br>
