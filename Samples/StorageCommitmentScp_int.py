import orthanc

def StorageCommitmentScpCallback(jobId, transactionUid, sopClassUids, sopInstanceUids, remoteAet, calledAet):
	print(jobId, transactionUid, remoteAet, calledAet)
	assert len(sopClassUids) == len(sopInstanceUids)
	for i in range(len(sopClassUids)):
		print("++", sopClassUids[i], sopInstanceUids[i])
	return 0

def StorageCommitmentLookup(sopClassUid, sopInstanceUid, data):
	print("??", sopClassUid, sopInstanceUid)
	data += 1
	if (data-1) % 2 == 0:
		return orthanc.StorageCommitmentFailureReason.SUCCESS
	else:
		return orthanc.StorageCommitmentFailureReason.NO_SUCH_OBJECT_INSTANCE

orthanc.RegisterStorageCommitmentScpCallback(StorageCommitmentScpCallback, StorageCommitmentLookup)
