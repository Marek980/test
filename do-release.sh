#!/bin/sh

# Specify the project directory that contains .git
slug="test"

# Specify release directory
dest="releases"

# Store releases in release directory
mkdir -p $dest

# Set the git working dir inside our project
export GIT_DIR=$slug/.git

# Get the latest tag
tag=$(git describe --tags --abbrev=0)

# Create a zip file out of the latest tag release
git archive $tag --prefix="$slug/" --format=zip --output="./$dest/$slug-$tag.zip"

echo "Created $dest/$slug-$tag.zip"
