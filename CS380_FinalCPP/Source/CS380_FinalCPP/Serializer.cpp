#include "Serializer.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"

bool USerializer::
SaveArrayText(FString saveDir, FString fileName, TArray<FString> text)
{
	saveDir += "\\";
	saveDir += fileName;
	//if(FPlatformFileManager::Get().GetPlatformFile())

	FString outString = "";
	for (FString& each : text)
	{
		outString += each;
		outString += LINE_TERMINATOR; // different rows of csv
	}

	return FFileHelper::SaveStringToFile(outString, *saveDir);

}
