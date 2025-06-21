GIT_COMMIT_ID := $(shell git rev-parse HEAD)
GIT_COMMIT_ID_SHORT := $(shell git rev-parse --short=7 HEAD)

GIT_BRANCH_NAME := $(shell git rev-parse --abbrev-ref HEAD)