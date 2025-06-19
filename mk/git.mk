COMMIT_ID := $(shell git rev-parse HEAD)
COMMIT_ID_SHORT := $(shell git rev-parse --short=8 HEAD)