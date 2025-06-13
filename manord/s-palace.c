// manord: 080a9774
// Manorsrvr.exe: 00491f8c
static const char *PlCommandTokens[] = {
    "LOCKED",       "NOLOOSEPROPS", "ARTIST",       "SHORTNAME",     "SHADOW",
    "FILL",         "PROPID",       "CRC",          "NAVAREA",       "ENDNAVAREA",
    "SERVERNAME",   "DEATHPENALTY", "MAXOCCUPANCY", "ROOMOCCUPANCY", "PURGEPROPDAYS",
    "MAXSESSIONID", "PICFOLDER",    "URL",          "HTTP_URL",      "BLURB",
    "ANNOUNCEMENT", "ROOMSFILE",    "ENTRANCE",     "ROOM",          "ID",
    "DROPZONE",     "NAME",         "DOOR",         "DEST",          "OUTLINE",
    "LOC",          "ENDDOOR",      "SPOT",         "SCRIPT",        "ENDSCRIPT",
    "ENDSPOT",      "SHOWNAME",     "DONTMOVEHERE", "PICTURE",       "ENDPICTURE",
    "TRANSCOLOR",   "PICTS",        "ENDPICTS",     "NOPAINTING",    "LOCKABLE",
    "BOLT",         "ENDBOLT",      "PRIVATE",      "NOGUESTS",      "PROP",
    "ENDPROP",      "SHUTABLE",     "NOCYBORGS",    "HIDDEN",        "OPERATORSONLY",
    "MAXMEMBERS",   "ENDROOM",      "END",          "PICT",          "FORWARD"};

// manord: 08099865
// Manorsrvr.exe: 0049277c
static const char spacing[] = "\r\t\n ";

// manord: 08058c54
// Manorsrvr.exe: 00412830
static int __cdecl plReadTokenized(FILE *file, char *output)
{
	bool bVar1;
	char *pcVar2;
	size_t sVar3;
	int iVar4;
	int iVar5;
	int iVar6;
	char (*_Buf2)[33];
	char (*_Str)[33];
	uint local_218;
	char local_214[512];
	char *local_14;

	iVar6 = 0;
	bVar1 = true;
	do
	{
		pcVar2 = fgets(local_214, 0x200, file);
		if (pcVar2 == NULL)
		{
			return iVar6;
		}
		if ((local_214[0] != ';') && (sVar3 = strlen(local_214), 2 < sVar3))
		{
			bVar1 = false;
			memset(output, 0, 0x200);
			local_14 = output;
			local_218 = 0;
			sVar3 = strlen(local_214);
			if (sVar3 != 0)
			{
				do
				{
					sVar3 = strspn(local_214 + local_218, spacing);
					iVar6 = local_218 + sVar3;
					if (local_214[iVar6] == '\"')
					{
						sVar3 = strcspn(local_214 + iVar6 + 1, "\"");
						sVar3 = sVar3 + 2;
						memcpy(local_14, local_214 + iVar6, sVar3);
						local_14[sVar3] = '\0';
						local_14 = local_14 + sVar3 + 1;
						local_218 = iVar6 + sVar3;
					}
					else
					{
						iVar5 = 0;
						_Str = PlCommandTokens;
						_Buf2 = PlCommandTokens;
						do
						{
							sVar3 = strlen(*_Str);
							iVar4 = memcmp(local_214 + iVar6, _Buf2, sVar3);
							if (iVar4 == 0)
								break;
							iVar5 = iVar5 + 1;
							_Str = _Str + 1;
							_Buf2 = _Buf2 + 1;
						} while (iVar5 < 0x3c);
						if (iVar5 < 0x3c)
						{
							*local_14 = (char)iVar5 + '\x01';
							local_14 = local_14 + 1;
							sVar3 = strlen(PlCommandTokens[iVar5]);
							iVar6 = iVar6 + sVar3 + 1;
							sVar3 = strspn(local_214 + iVar6, spacing);
							local_218 = iVar6 + sVar3;
						}
						else
						{
							sVar3 = strcspn(local_214 + iVar6, spacing);
							sVar3 = sVar3 + 1;
							memcpy(local_14, local_214 + iVar6, sVar3);
							local_14 = local_14 + sVar3;
							local_14[-1] = '\0';
							local_218 = iVar6 + sVar3;
						}
					}
					sVar3 = strlen(local_214);
				} while (local_218 < sVar3);
			}
			iVar6 = (size_t)local_14 - (size_t)output;
		}
		if (!bVar1)
		{
			return iVar6;
		}
	} while (true);
}
