.text:004011E0                 push    ebp
.text:004011E1                 push    esi
.text:004011E2                 push    edi
.text:004011E3                 push    0              
.text:004011E5                 call    _time
.text:004011EA                 mov     edi, [esp+10h+arg_8]
.text:004011EE                 mov     ebp, [esp+10h+arg_4]
.text:004011F2                 add     esp, 4
.text:004011F5                 xor     esi, esi
.text:004011F7                 test    ebp, ebp
.text:004011F9                 mov     [edi], eax
.text:004011FB                 jle     short loc_401223
.text:004011FD                 mov     ecx, [esp+0Ch+arg_0]
.text:00401201                 push    ebx
.text:00401202                 imul    eax, 7452845h
.text:00401208                 mov     bl, [esi+ecx]
.text:0040120B                 add     eax, 2934563h
.text:00401210                 mov     edx, eax
.text:00401212                 shr     edx, 17h
.text:00401215                 xor     bl, dl
.text:00401217                 add     bl, al
.text:00401219                 mov     [edi+esi+4], bl
.text:0040121D                 inc     esi
.text:0040121E                 cmp     esi, ebp
.text:00401220                 jl      short loc_401202
.text:00401222                 pop     ebx
.text:00401223                 pop     edi
.text:00401224                 pop     esi
.text:00401225                 pop     ebp
.text:00401226                 retn
