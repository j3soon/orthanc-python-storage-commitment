import orthanc

count = None

def StorageCommitmentScpCallback(jobId, transactionUid, sopClassUids, sopInstanceUids, remoteAet, calledAet):
	global count
	print(jobId, transactionUid, remoteAet, calledAet)
	assert len(sopClassUids) == len(sopInstanceUids)
	for i in range(len(sopClassUids)):
		print("++", sopClassUids[i], sopInstanceUids[i])
	count = 0
	return None

def StorageCommitmentLookup(sopClassUid, sopInstanceUid, data):
	global count
	print("??", sopClassUid, sopInstanceUid)
	count += 1
	if (count-1) % 2 == 0:
		return orthanc.StorageCommitmentFailureReason.SUCCESS
	else:
		return orthanc.StorageCommitmentFailureReason.NO_SUCH_OBJECT_INSTANCE

orthanc.RegisterStorageCommitmentScpCallback(StorageCommitmentScpCallback, StorageCommitmentLookup)
