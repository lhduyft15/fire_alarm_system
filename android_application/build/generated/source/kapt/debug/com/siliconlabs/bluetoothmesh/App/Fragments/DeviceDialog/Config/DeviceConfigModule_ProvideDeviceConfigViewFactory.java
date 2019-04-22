// Generated by Dagger (https://google.github.io/dagger).
package com.siliconlabs.bluetoothmesh.App.Fragments.DeviceDialog.Config;

import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.inject.Provider;

public final class DeviceConfigModule_ProvideDeviceConfigViewFactory
    implements Factory<DeviceConfigView> {
  private final DeviceConfigModule module;

  private final Provider<DeviceConfigFragment> deviceConfigFragmentProvider;

  public DeviceConfigModule_ProvideDeviceConfigViewFactory(
      DeviceConfigModule module, Provider<DeviceConfigFragment> deviceConfigFragmentProvider) {
    this.module = module;
    this.deviceConfigFragmentProvider = deviceConfigFragmentProvider;
  }

  @Override
  public DeviceConfigView get() {
    return provideInstance(module, deviceConfigFragmentProvider);
  }

  public static DeviceConfigView provideInstance(
      DeviceConfigModule module, Provider<DeviceConfigFragment> deviceConfigFragmentProvider) {
    return proxyProvideDeviceConfigView(module, deviceConfigFragmentProvider.get());
  }

  public static DeviceConfigModule_ProvideDeviceConfigViewFactory create(
      DeviceConfigModule module, Provider<DeviceConfigFragment> deviceConfigFragmentProvider) {
    return new DeviceConfigModule_ProvideDeviceConfigViewFactory(
        module, deviceConfigFragmentProvider);
  }

  public static DeviceConfigView proxyProvideDeviceConfigView(
      DeviceConfigModule instance, DeviceConfigFragment deviceConfigFragment) {
    return Preconditions.checkNotNull(
        instance.provideDeviceConfigView(deviceConfigFragment),
        "Cannot return null from a non-@Nullable @Provides method");
  }
}
