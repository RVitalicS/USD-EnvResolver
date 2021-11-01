# USD Environment Resolver

An environment variables based asset path resolver plugin for USD



## Building

You'll need the following libraries to build the project

| Package           | Version        |
| ----------------- | -------------- |
| CMAKE             | 3.0+           |
| USD               | 21.0+          |

Configure the PXR\_USD\_LOCATION environment variable or pass the location of the installed USD using -D\<varname\>=\<path\> to cmake



## Debug code

Adding following token to *TF_DEBUG* will print Environment Resolver information

```bash
export TF_DEBUG=USD_ENV_RESOLVER
```



## Usage of the Environment resolver.

* Help plugin system to find _plugInfo.json_

```bash
export PXR_PLUGINPATH_NAME=${ENV_RESOLVER_INSTALL_DIR}/plugin/usd
```


* Use environment variables in usd files

```
#usda 1.0
(
    defaultPrim = "root"
)
def "root" (
    references = @${ASSETS}/asset.usd@
)
{
}
```