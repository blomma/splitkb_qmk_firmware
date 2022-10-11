# Splitkb.com orphan asset branch

QMK has a policy that images are now allowed in the repository,
as it greatly increases the size of the repository.
This is a completely valid point given the number of keyboards it contains.

However, we still need to add images! QMK recommends uploading them to Imgur,
but relying on a third-party service for it is not ideal.

This branch is a workaround for this problem.

## How to add images

Simply add them to the repository and push to `assets`.

For example, the image `example.png` becomes available
at `https://raw.githubusercontent.com/splitkb/qmk_firmware/assets/example.png`.

![](https://raw.githubusercontent.com/splitkb/qmk_firmware/assets/example.png)

Do keep in mind that QMK prefers images which are not *huge*:
The Imgur upload instructions use a resolution of 1024x1024.

## What's up with the branch?

This is an [orphan branch](https://git-scm.com/docs/git-checkout#Documentation/git-checkout.txt---orphanltnew-branchgt), meaning it does not share _any_ commits with QMK itself.
It is essentially a separate commit history in the same repo.

### Doesn't this still increase the repository size?

Yes, but only for our own fork at `https://github.com/splitkb/qmk_firmware/`.
The upstream repository is not affected.

We try to upstream all our code. This means our fork *should* not be used by end users.
It is only a staging area for our pull requests, so it only impacts our own developers.
