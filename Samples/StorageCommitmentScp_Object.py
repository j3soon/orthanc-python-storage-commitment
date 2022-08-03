import orthanc

class CallbackData(object):
	def __init__(self):
		print("Constructor called.")
		self.count = 0
	def __del__(self):
		print("Destructor called.")
	def count_post_increment(self):
		self.count += 1
		return self.count - 1

def StorageCommitmentScpCallback(jobId, transactionUid, sopClassUids, sopInstanceUids, remoteAet, calledAet):
	print(jobId, transactionUid, remoteAet, calledAet)
	assert len(sopClassUids) == len(sopInstanceUids)
	for i in range(len(sopClassUids)):
		print("++", sopClassUids[i], sopInstanceUids[i])
	data = CallbackData() # any Python native type or self-defined class
	return data

def StorageCommitmentLookup(sopClassUid, sopInstanceUid, data):
	print("??", sopClassUid, sopInstanceUid)
	if data.count_post_increment() % 2 == 0:
		return orthanc.StorageCommitmentFailureReason.SUCCESS
	else:
		return orthanc.StorageCommitmentFailureReason.NO_SUCH_OBJECT_INSTANCE

orthanc.RegisterStorageCommitmentScpCallback(StorageCommitmentScpCallback, StorageCommitmentLookup)
